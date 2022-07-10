/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1

Example 3:
Input: grid = [[0,2]]
Output: 0
*/

int orangesRotting(vector<vector<int>>& arr) {
    int n = arr.size(), m = arr[0].size();
    queue<pair<int, int>> q;
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (arr[i][j] == 2)
                q.push({i, j});
            else if (arr[i][j] == 1)
                count++;
        }
    }
    
    int ans = 0;
    vector<int> dir = {-1, 0, 1, 0, -1};
    while (!q.empty() && count > 0) {
        int sz = q.size();
        while (sz--) {
            pair<int, int> f = q.front();
            q.pop();
            
            for(int k = 0; k < 4; k++) {
                int i = f.first + dir[k];
                int j = f.second + dir[k+1];
                if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == 1) {
                    arr[i][j] = 2;
                    q.push({i, j});
                    count--;
                }
            }
        }
        ans++;
    }
    
    if (count > 0)
        return -1;
    
    return ans;
}
