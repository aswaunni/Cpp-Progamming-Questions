/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
*/

vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    vector<int> comb;
    backtrack(ans, 0, target, comb, nums);
    return ans;
}

void backtrack(vector<vector<int>>& ans, int itr, int rem, vector<int>& comb, vector<int>& nums) {
    if (rem == 0) {
        ans.push_back(comb);
        return;
    }
    
    for (int i = itr; i < nums.size(); i++) {
        if(nums[i] > rem) 
            return;
        
        if (i > itr && nums[i] == nums[i-1])
            continue;
        comb.push_back(nums[i]);
        backtrack(ans, i+1, rem-nums[i], comb, nums);
        comb.pop_back();
    }
}
