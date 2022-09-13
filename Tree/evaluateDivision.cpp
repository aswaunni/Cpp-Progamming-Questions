/*
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
*/

double find(unordered_map<string, vector<pair<string, double>>>& adj, string s, string e, double x, unordered_map<string, bool>& vis) {
    if (s == e) 
        return x;
    
    vis[s] = true;
    for (auto& a : adj[s]) {
        if (!vis[a.first]) {
            double y = find(adj, a.first, e, x*a.second, vis);
            if (y >= 0)
                return y;
        }
    }
    vis[s] = false;
    return -1.0;
}

vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& v, vector<vector<string>>& q) {
    unordered_map<string, vector<pair<string, double>>> adj;
    
    for (int i = 0; i < eq.size(); i++) {
        adj[eq[i][0]].push_back({eq[i][1], v[i]});
        adj[eq[i][1]].push_back({eq[i][0], (1/v[i])});
    }
    
    vector<double> ans;
    for (int i = 0; i < q.size(); i++) {
        string s = q[i][0], e = q[i][1];
        if (!adj.count(s) || !adj.count(e))
            ans.push_back(-1.0);
        else {
            unordered_map<string, bool> vis;
            ans.push_back(find(adj, q[i][0], q[i][1], 1.0, vis));
        }
    }
    return ans;
}
