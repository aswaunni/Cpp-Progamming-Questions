/*
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
*/

int maxSubarraySumCircular(vector<int>& nums) {
    int minSum = nums[0], maxSum = nums[0];
    int minHere = 0, maxHere = 0, total = 0;
    
    for (auto& a : nums) {
        minHere = min(minHere + a, a);
        maxHere = max(maxHere + a, a);
        
        minSum = min(minSum, minHere);
        maxSum = max(maxSum, maxHere);
        
        total += a;
    }
    
    return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
}
