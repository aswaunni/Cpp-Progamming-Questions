/*
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
*/

int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    for (auto& s : strs) {
        int ones = count(s.begin(), s.end(), '1');
        int zeroes = s.length() - ones;
        
        for (int i = m; i >= zeroes; i--) {
            for (int j = n; j >= ones; j--)
                dp[i][j] = max(dp[i][j], 1 + dp[i-zeroes][j-ones]);
        }
    }
    return dp[m][n];
}

// OR (Mine)

int countOnes(string s) {
    int ans = 0;
    for (auto& c : s) {
        if (c == '1')
            ans++;
    }
    return ans;
}
int ans = 0;
int dfs(vector<pair<int, int>>& v, int m, int n, int i) {
    if (i >= v.size() || (m == 0 && n == 0))
        return 0;
    
    int with = 0;
    if (m >= v[i].first && n >= v[i].second)
        with = 1 + dfs(v, m - v[i].first, n - v[i].second, i+1);
    int without = dfs(v, m, n, i+1);
    return max(with, without);
}

int findMaxForm(vector<string>& strs, int m, int n) {
    vector<pair<int, int>> v;
    
    for (auto& a : strs) {
        int x = a.length();
        int ones = countOnes(a);
        v.push_back({x-ones, ones});
    }
    
    return dfs(v, m, n, 0);
}    
