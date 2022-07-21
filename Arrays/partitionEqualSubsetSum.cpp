/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 
 */

// DP

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    
    if (sum%2 == 1)
        return false;
    
    vector<bool> dp(sum/2, false);
    dp[0] = true;
    
    for (int i = 0; i < nums.size(); i++) {
        for (int j = sum/2; j > 0; j--) {
            if (j >= nums[i])
                dp[j] = dp[j] | dp[j - nums[i]];
        }
    }
    return dp[sum/2];
}

// Bit Manipulation

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    
    if (sum%2 == 1)
        return false;
    
    bitset<10001> bits(0);
    bits[0] = 1;
    
    for (auto& a : nums)
        bits |= (bits << a);

    return bits[sum >> 1];
}
