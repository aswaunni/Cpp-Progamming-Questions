/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    
    for (int i = 0; i < (1 << n); i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j))
                v.push_back(nums[j]);
        }
        ans.push_back(v);
    }
    return ans;
}

// OR Recursion

    void helper(vector<int>& nums, vector<int>& sub, vector<vector<int>>& ans, int s) {
        ans.push_back(sub);
        for (int i = s; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            helper(nums, sub, ans, i+1);
            sub.pop_back();
        }
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub = {};
        helper(nums, sub, ans, 0);
        return ans;
    }
