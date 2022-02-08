/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1:

Input: nums = [3,0,1]
Output: 2
*/

int missingNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 1; i <= nums.size(); i++) {
        ans ^= i;
        ans ^= nums[i-1];
    }
    return ans;
}
