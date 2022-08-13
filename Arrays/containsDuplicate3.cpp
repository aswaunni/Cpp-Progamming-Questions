/*
Given an integer array nums and two integers k and t, return true if there are two distinct indices i and j in the array such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<long> s;
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > k)
            s.erase(s.lower_bound(nums[i-k-1]));
        
        auto itr = s.lower_bound(nums[i] - (long)t);
        if(itr != s.end() && (*itr - nums[i]) <= t)
            return true;
        s.insert(nums[i]);
    }
    return false;
}
