/*
Given an array Arr of size N containing positive integers. Find the maximum sum of a subsequence such that no two numbers in the sequence should be adjacent in the array.

Example 1:

Input:
N = 6
Arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
Explanation: If you take indices 0, 3
and 5, then Arr[0]+Arr[3]+Arr[5] =
5+100+5 = 110.
Example 2:

Input:
N = 4
Arr[] = {3, 2, 7, 10}
Output: 13
Explanation: 3 and 10 forms a non
continuous  subsequence with maximum
sum.
*/

int findMaxSum(int *arr, int n) {
    int s1 = arr[0], s2 = 0;
    
    for (int i = 1; i < n; i++) {
        int temp = max(s1, s2);
        
        s1 = s2 + arr[i];
        s2 = temp;
    }
    return max(s1, s2);
}

// OR

	int findMaxSum(int *arr, int n) {
    vector<int> dp(n, 0);
    
    if (n == 1)
        return arr[0];
        
    if (n == 2)
        return max(arr[0], arr[1]);
        
    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = arr[0] + arr[2];
    
    for (int i = 3; i < n; i++)
        dp[i] = arr[i] + max(dp[i-2], dp[i-3]);

    return max(dp[n-1], dp[n-2]);
}
