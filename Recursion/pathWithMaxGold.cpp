/*
In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 
Example 1:
Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24

Example 2:
Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
*/

vector<int> dir = {0, 1, 0, -1, 0};
int dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
        return 0;
    
    int original = grid[i][j];
    grid[i][j] = 0;
    
    int sum = 0;
    
    for (int d = 0; d < 4; d++) {
        int x = i+dir[d], y = j+dir[d+1];
        sum = max(sum, dfs(grid, x, y, n, m));
    }
    
    grid[i][j] = original;
    return sum + grid[i][j];
}
int getMaximumGold(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]) {
                ans = max(ans, dfs(grid, i, j, n, m));
            }
        }
    }
    return ans;
}
