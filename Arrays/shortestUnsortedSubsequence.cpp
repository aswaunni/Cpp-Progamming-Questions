/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
*/

int findUnsortedSubarray(vector<int>& nums) {
    int s = -1, e = -2, n = nums.size();
    int mx = nums[0], mn = nums[n-1];
    for (int i = 0; i < n; i++) {
        mx = max(nums[i], mx);
        mn = min(nums[n-i-1], mn);
        
        if (nums[i] < mx)
            e = i;
        if (nums[n-i-1] > mn)
            s = n-i-1;
    }
    return e-s+1;
}
