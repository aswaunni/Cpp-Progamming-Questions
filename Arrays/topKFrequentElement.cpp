/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = nums.size();
    
    map<int, int> m;
    for (auto& a : nums) m[a]++;
    
    vector<vector<int>> buckets(n+1);
    for (auto& a : m)
        buckets[a.second].push_back(a.first);
    
    vector<int> ans;
    for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; i--) {
        for (auto& a : buckets[i])
            ans.push_back(a);
        if (ans.size() == k)
            break;
    }
    return ans;
}
