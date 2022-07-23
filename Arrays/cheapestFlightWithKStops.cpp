/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example 1:
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Example 2:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
*/

// Bellman-Ford
/*  In bellman-ford algo calculates the shortest distance from the source
    point to all of the vertices.
    Time complexity of Bellman-Ford is O(VE),
*/

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    /* cost from source to all other nodes */
    vector<int> cost( n, INT_MAX );
    cost[src] = 0;
    
    for (int i = 0; i < k+1; i++) {
        vector<int> tmp(cost);
        for (auto& a : flights) {
            if (cost[a[0]] != INT_MAX)
                tmp[a[1]] = min(tmp[a[1]], cost[a[0]] + a[2]);
        }
        cost = tmp;
    }
    return cost[dst] == INT_MAX ? -1 : cost[dst];
}

// OR (DFS)

void dfs(unordered_map<int, vector<pair<int, int>>>& m, int src, int dst, int k, int sum, vector<int>& vis, int& ans) {
    if (dst == src) {
        ans = sum;
        return;
    }
    
    if (k == 0)
        return;
    
    vis[src] = true;
    
    for (auto& a : m[src]) {
        if (!vis[a.first] && sum + a.second < ans)
            dfs(m, a.first, dst, k-1, sum+a.second, vis, ans);
    }
    vis[src] = false;
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    unordered_map<int, vector<pair<int, int>>> m;
    
    for (auto& a : flights)
        m[a[0]].push_back({a[1], a[2]});
    
    vector<int> vis(n, false);
    int ans = INT_MAX;
    dfs(m, src, dst, k+1, 0, vis, ans);
    return (ans == INT_MAX ? -1 : ans);
    
}
