/*
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

 

Example 1:


Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:


Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
*/

struct T {
    int t, x, y;
    T(int a, int b, int c) : t (a), x (b), y (c){}
    bool operator< (const T &d) const {return t > d.t;}
};

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vector<int> dir = {-1, 0, 1, 0, -1};
    priority_queue<T> q;
    q.push(T(grid[0][0], 0, 0));
    vis[0][0] = true;

    int ans = 0;
    while (true) {
        auto tp = q.top();
        q.pop();

        ans = max(ans, tp.t);
        if (tp.x == n-1 && tp.y == n-1)
            return ans;

        for (int k = 0; k < 4; k++) {
            int i = tp.x + dir[k], j = tp.y + dir[k+1];
            if (i >= 0 && j >= 0 && i < n && j < n && !vis[i][j]) {
                vis[i][j] = true;
                q.push(T(grid[i][j], i, j));
            }
        }
    }
}
