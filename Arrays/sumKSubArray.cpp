/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
*/

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int sum = 0;
    int ans = 0;
    m[0] = 1;
    
    for (auto& a : nums) {
        sum += a;
        int find = sum - k;
        if (m.count(find)) {
            ans += m[find];
        }
        m[sum]++;
    }
    return ans;
}
