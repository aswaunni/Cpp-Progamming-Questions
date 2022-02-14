/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.

*/

    int equalPartition(int n, int arr[])
    {
        int sum = accumulate(arr, arr+n, 0);
        if (sum%2 != 0)
            return 0;
            
        sum /= 2;
        
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for (int i = 0; i < n + 1; i++)
            dp[i][0]=1;

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j< sum + 1; j++) {
                if (arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
       return dp[n][sum];
    }
