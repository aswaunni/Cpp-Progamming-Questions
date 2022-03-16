/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
*/

int maximalSquare(vector<vector<char>>& mtx) {
    int n = mtx.size(), m = mtx[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mtx[i-1][j-1] == '1') {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans*ans;
}
