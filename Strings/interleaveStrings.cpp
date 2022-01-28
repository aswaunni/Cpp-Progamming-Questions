/*
Given strings A, B, and C, find whether C is formed by an interleaving of A and B.

An interleaving of two strings S and T is a configuration such that it creates a new string Y from the concatenation substrings of A and B and |Y| = |A + B| = |C|

For example:

A = "XYZ"

B = "ABC"

so we can make multiple interleaving string Y like, XYZABC, XAYBCZ, AXBYZC, XYAZBC and many more so here your task is to check whether you can create a string Y which can be equal to C.

Specifically, you just need to create substrings of string A and create substrings B and concatenate them and check whether it is equal to C or not.

Note: a + b is the concatenation of strings a and b.

Return true if C is formed by an interleaving of A and B, else return false.

Example 1:

Input:
A = YX, B = X, C = XXY
Output: 0
Explanation: XXY is not interleaving
of YX and X
Example 2:

Input:
A = XY, B = X, C = XXY
Output: 1
Explanation: XXY is interleaving of
XY and X.
*/

bool isInterleave(string a, string b, string c) 
{
    int n = a.size();
    int m = b.size();
    if(c.size() != n+m)
       return false;
       
    bool dp[n+1][m+1];
    memset(dp, false, sizeof(dp));
    
    dp[0][0] = true;
    for (int i= 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i > 0 && a[i-1] == c[i+j-1] && dp[i-1][j])
                dp[i][j] = true;
            if (j > 0 && b[j-1] == c[i+j-1] && dp[i][j-1])
                dp[i][j] = true;
        }
    }
    return dp[n][m];
}
