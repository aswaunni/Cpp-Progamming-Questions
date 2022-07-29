/*
We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
*/

bool dfs(vector<vector<int>>& adj, map<int, int>& m, int i, int team) {
        
    if (m.count(i))
        return m[i] == team;
    
    m[i] = team;
    
    for (auto& j : adj[i])
        if (!dfs(adj, m, j, 1^team))
            return false;

    return true;
}

bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>> adj(n+1);
    
    for (auto& a : dislikes) {
        adj[a[0]].push_back(a[1]);
        adj[a[1]].push_back(a[0]);
    }
    
    map<int, int> m;
    
    for (int i = 1; i <= n; i++) {
        if (!m.count(i) && !dfs(adj, m, i, 0))
            return false;
    }
    
    return true;
}

// OR

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>> adj(n+1);
    
    for (auto& a : dislikes) {
        adj[a[0]].push_back(a[1]);
        adj[a[1]].push_back(a[0]);
    }
    
    map<int, int> m;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (m.count(i))
            continue;
        
        q.push(i);
        m[i] = 0;
        
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            
            for (auto& a : adj[f]) {
                if (m.count(a)) {
                    if (m[a] == m[f])
                        return false;
                    continue;
                } 
                
                q.push(a);
                m[a] = 1^m[f];
            }
        }
    }
    return true;
}
