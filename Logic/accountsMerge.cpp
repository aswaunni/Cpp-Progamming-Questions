/*
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Example 2:

Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
*/

// Union Find

vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
    map<string, string> owner;
    map<string, string> parents;
    map<string, set<string>> unions;
    for (int i = 0; i < acts.size(); i++) {
        for (int j = 1; j < acts[i].size(); j++) {
            parents[acts[i][j]] = acts[i][j];
            owner[acts[i][j]] = acts[i][0];
        }
    }
    for (int i = 0; i < acts.size(); i++) {
        string p = find(acts[i][1], parents);
        for (int j = 2; j < acts[i].size(); j++)
            parents[find(acts[i][j], parents)] = p;
    }
    for (int i = 0; i < acts.size(); i++)
        for (int j = 1; j < acts[i].size(); j++)
            unions[find(acts[i][j], parents)].insert(acts[i][j]);

    vector<vector<string>> res;
    for (pair<string, set<string>> p : unions) {
        vector<string> emails(p.second.begin(), p.second.end());
        emails.insert(emails.begin(), owner[p.first]);
        res.push_back(emails);
    }
    return res;
}

string find(string s, map<string, string>& p) {
    return p[s] == s ? s : find(p[s], p);
}

// OR (DFS)

    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
    for (auto& a : acts) {
        for (int i = 2; i < a.size(); i++) {
            adj[a[i]].push_back(a[i-1]);
            adj[a[i-1]].push_back(a[i]);
        }
    }

    for (auto& a : acts) {
        if (!vis.count(a[1])) {
            vector<string> email = {a[0]};
            dfs(a[1], email);
            sort(email.begin()+1, email.end());
            ans.push_back(email);
        }
    }
    return ans;
}

void dfs(string a, vector<string>& email) {
    vis.insert(a);
    email.push_back(a);

    for (auto& b : adj[a]) {
        if (!vis.count(b))
            dfs(b, email);
    }
}

unordered_map<string, vector<string>> adj;  
unordered_set<string> vis;               
vector<vector<string>> ans;  
