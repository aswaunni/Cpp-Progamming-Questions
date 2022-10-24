/*
You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

 

Example 1:


Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
Example 2:


Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
Output: -1
Explanation: We need to eliminate at least two obstacles to find such a walk.
*/

int shortestPath(vector<vector<int>>& grid, int k) {
    int n = grid.size(), m = grid[0].size();
    vector<int> dir= {1, 0, -1, 0, 1};
    vector<vector<int>> vis(n, vector<int>(m, -1));
    queue<vector<int>> q;
    q.push({0, 0, 0, k});

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto t = q.front();
            int x = t[0], y = t[1];
            q.pop();

            if (x < 0 || y < 0 || x >= n || y >= m)
                continue;

            if (x == n-1 && y == m-1)
                return t[2];

            if (grid[x][y] == 1) {
                if (t[3] > 0)
                    t[3]--;
                else
                    continue;
            }

            if (vis[x][y] != -1 && vis[x][y] >= t[3])
                continue;

            vis[x][y] = t[3];

            for (int i = 0; i < 4; i++) {
                int x1 = x + dir[i], y1 = y + dir[i+1];
                q.push({x1, y1, t[2]+1, t[3]});
            }

        }
    }
    return -1;
}
