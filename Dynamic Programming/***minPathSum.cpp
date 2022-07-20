/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
*/

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    
    vector<vector<int>> dp(grid);
    
    for (int i = 1; i < n; i++) grid[i][0] += grid[i-1][0];
    for (int j = 1; j < m; j++) grid[0][j] += grid[0][j-1];
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
        }
    }
    return grid[n-1][m-1];
}

// OR (More efficient 1D dp)

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    
    vector<int> dp(m, grid[0][0]); // corresponds to 0th row
    
    for (int j = 1; j < m; ++j)
        dp[j] = dp[j-1] + grid[0][j];
    
    for (int i = 1; i < n; ++i) {
        dp[0] += grid[i][0]; // 0th column
        for (int j = 1; j < m; ++j)
            dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
    }
    return dp[m-1];
}
