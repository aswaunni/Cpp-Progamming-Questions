/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/

int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0, r = 0;
    int ans = INT_MAX;
    int sum = 0;
    
    while (r < nums.size()) {
        sum += nums[r++];
        
        while (sum >= target) {
            ans = min(ans, r-l);
            sum -= nums[l++];
        }
    }
    return (ans == INT_MAX ? 0 : ans);
}

// OR

int minSubArrayLen(int k, vector<int>& nums) {
    int n = nums.size();
    vector<int> sum(n+1, 0);
    
    for (int i = 0; i < n; i++)
        sum[i+1] = sum[i] + nums[i];
    
    int ans = INT_MAX;
    for (int i = n; i >= 0 && sum[i] >= k; i--) {
        int j = upper_bound(sum.begin(), sum.end(), sum[i]-k) - sum.begin();
        ans = min(ans, i - j + 1);
    }
    return (ans == INT_MAX ? 0 : ans);
}
