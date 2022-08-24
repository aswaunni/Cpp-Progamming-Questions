/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
*/

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    int mod = 1e9 + 7;
    int ans = 0;
    
    stack<int> s;
    vector<int> dp(n, 0);
    
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] > arr[i])
            s.pop();
        
        if (s.empty())
            dp[i] = (i+1) * arr[i];
        else
            dp[i] = (dp[s.top()] + (i - s.top()) * arr[i]) % mod;
        s.push(i);
        ans = (ans + dp[i]) % mod;
    }
    return ans;
}
