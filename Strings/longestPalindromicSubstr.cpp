/*
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
*/
int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<int> dp(n, 0), prev(n, 0);
    
    for (int i = n-1; i >= 0; i--) {
        dp[i] = 1;
        for (int j = i+1; j < n; j++) {
            if (s[i] == s[j])
                dp[j] = 2 + prev[j-1];
            else
                dp[j] = max(prev[j], dp[j-1]);
        }
        dp.swap(prev);
    }
    return prev[n-1];
}

// OR

int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int i = n-1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i+1; j < n; j++) {
            if (s[i] == s[j])
                dp[i][j] = 2 + dp[i+1][j-1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

// OR

int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == s[n-j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}
