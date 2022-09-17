/*
Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Example 2:

Input: nums = [1,2,3,4], k = 3
Output: false
 

Constraints:

1 <= k <= nums.length <= 16
1 <= nums[i] <= 104
The frequency of each element is in the range [1, 4].
*/

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum%k)
        return false;
    
    vector<bool> vis(n);
    sort(vis.begin(), vis.end(), greater<int>());
    return dfs(nums, k, vis, sum/k, 0, 0);
}

bool dfs(vector<int>& nums, int k, vector<bool>& vis, int sum, int i, int cur_sum) {
    if (k == 1)
        return true;
    
    if (i >= nums.size())
        return false;
    
    if (sum == cur_sum)
        return dfs(nums, k-1, vis, sum, 0, 0);
    
    for (int j = i; j < nums.size(); j++) {
        if (vis[j] || cur_sum + nums[j] > sum)
            continue;
        vis[j] = true;
        if (dfs(nums, k, vis, sum, i+1, cur_sum + nums[j]))
            return true;
        vis[j] = false;
    }
    return false;
}
