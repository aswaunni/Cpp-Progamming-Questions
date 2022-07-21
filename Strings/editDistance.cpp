/*
Given two strings s and t. Return the minimum number of operations required to convert s to t.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
 

Example 1:

Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.
Example 2:

Input : 
s = "gfg", t = "gfg"
Output: 
0
Explanation: Both strings are same.
*/

int helper(string s, string t, int n, int m) {
    if (n == 0)
        return m;
        
    if (m == 0)
        return n;
    
    if (s[n-1] == t[m-1])
        return helper(s, t, n-1, m-1);
   
    return 1 + 
        min(helper(s, t, n-1, m),
            min(helper(s, t, n-1, m-1), helper(s, t, n, m-1)));
    
}
int editDistance(string s, string t) {
    int n = s.length(), m = t.length();
    return helper(s, t, n, m);
}

// OR (DP)

int helper(string s, string t, int n, int m, vector<vector<int>>& dp) {
    if (n == 0)
        return m;
        
    if (m == 0)
        return n;
    
    if (dp[n][m] != -1)
        return dp[n][m];
    
    if (s[n-1] == t[m-1])
        return dp[n][m] = helper(s, t, n-1, m-1, dp);
   
    return dp[n][m] = 1 + 
        min(helper(s, t, n-1, m, dp),
            min(helper(s, t, n-1, m-1, dp), helper(s, t, n, m-1, dp)));
    
}
int editDistance(string s, string t) {
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return helper(s, t, n, m, dp);
}
