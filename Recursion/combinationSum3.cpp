/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 
*/

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    vector<int> comb;
    backtrack(ans, 0, target, comb, nums);
    return ans;
}

void backtrack(vector<vector<int>>& ans, int itr, int rem, vector<int>& comb, vector<int>& nums) {
    if (rem < 0)
        return;
    if (rem == 0) {
        ans.push_back(comb);
        return;
    }
    
    for (int i = itr; i < nums.size(); i++) {
        comb.push_back(nums[i]);
        backtrack(ans, i, rem-nums[i], comb, nums);
        comb.pop_back();
    }
}
