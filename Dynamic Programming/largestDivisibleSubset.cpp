/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
*/

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    
    if (n == 0 || n == 1)
        return nums;
    
    sort(nums.begin(), nums.end());
    
    vector<int> dp(n, 1), pred(n, -1), ans;
    int mx_i = 0;
    
    for (int i = 1; i< n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i]%nums[j] == 0 && dp[j]+1 > dp[i]) {
                dp[i] = dp[j] + 1;
                pred[i] = j;
            }
        }
        if (dp[i] > dp[mx_i])
            mx_i = i;
    }
    
    for (; mx_i >= 0; mx_i = pred[mx_i])
        ans.push_back(nums[mx_i]);
    
    return ans;
}
