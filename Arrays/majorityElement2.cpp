/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
*/

/*
Boyer–Moore majority vote algorithm

Based on forming triplets and finding the excess elements
https://leetcode.com/problems/majority-element-ii/discuss/543672/BoyerMoore-majority-vote-algorithm-EXPLAINED
*/

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int x = -1, y = -1, cx = 0, cy = 0;
    
    for (auto& a : nums) {
        if (a == x)
            cx++;
        else if (a == y)
            cy++;
        else if (cx == 0) {
            cx++;
            x = a;
        } else if (cy == 0) {
            cy++;
            y = a;
        } else {
            cx--;
            cy--;
        }
    }
    
    vector<int> ans;
    
    if (cx == 0 && cy == 0)
        return ans;
    
    cx = cy = 0;
    
    for (auto& a : nums) {
        if (a == x) cx++;
        else if (a == y) cy++;
    }
    
    if (cx > n/3) ans.push_back(x);
    if (cy > n/3) ans.push_back(y);
    
    return ans;
}
