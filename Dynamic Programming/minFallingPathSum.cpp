/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
*/

int minFallingPathSum(vector<vector<int>>& mat) {
    int ans = INT_MAX, n = mat.size();
            
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] += min(mat[i-1][j], min(mat[i-1][max(0, j-1)], mat[i-1][min(n-1, j+1)]));
        }
    }

    for (int j = 0; j < n; j++)
        ans = min(ans, mat[n-1][j]);
    return ans;
}

// OR

int dfs(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp) {
    int n = mat.size();
    
    if (i == (n-1) && j < n && j >= 0)
        return mat[i][j];
    if (j >= n || j < 0)
        return INT_MAX;
    
    if (dp[i][j] != INT_MAX)
        return dp[i][j];
    
    return dp[i][j] = mat[i][j] + min(dfs(mat, i+1, j, dp), min(dfs(mat, i+1, j-1, dp), dfs(mat, i+1, j+1, dp)));
}

int minFallingPathSum(vector<vector<int>>& mat) {
    int ans = INT_MAX, n = mat.size();
    
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    
    for (int j = 0; j < n; j++)
        ans = min(ans, dfs(mat, 0, j, dp));

    return ans;
}
