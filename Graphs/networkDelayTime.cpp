/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
*/

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> dir(n+1);
    
    for (auto& a : times)
        dir[a[0]].push_back({a[1], a[2]});
    
    vector<int> cnt(n+1, INT_MAX);
    vector<int> vis(n+1, false);
    
    cnt[0] = 0;
    cnt[k] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, k});
    
    int u, v, w;
    while (!q.empty()) {
        u = q.top().second;
        q.pop();
        
        if (vis[u])
            continue;
        
        vis[u] = true;
        
        for (auto& a : dir[u]) {
            v = a.first, w = a.second;
            
            if (cnt[v] > cnt[u] + w) {
                cnt[v] = cnt[u] + w;
                q.push({cnt[v], v});
            } 
        }
    }
    
    int ans = *max_element(cnt.begin(), cnt.end());
    return (ans == INT_MAX ? -1 : ans);
}
