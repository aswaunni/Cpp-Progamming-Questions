/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

void helper(vector<int>& nums, vector<vector<int>>&ans, vector<int>& v, int start) {
    ans.push_back(v);
    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i-1])
            continue;
        v.push_back(nums[i]);
        helper(nums, ans, v, i+1);
        v.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> v;
    
    sort(nums.begin(), nums.end());
    helper(nums, ans, v, 0);
    return ans;
}
