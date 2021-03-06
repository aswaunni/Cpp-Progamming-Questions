/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
*/

void check(vector<vector<int>>& isConnected, vector<bool>& vis, int start, int n) {
    vis[start] = true;
    for (int j = 0; j < n; ++j) {
        if (isConnected[start][j] && !vis[j])
            check(isConnected, vis, j, n);
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> vis(n, false);
    int ans = 0;
    
    for (int i = 0; i < n; ++i ) {
        if (!vis[i]) {
            ++ans;
            check(isConnected, vis, i, n);
        }
    }
    return ans;
}
