/*
Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

 

Example 1:

Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Example 2:

Input: nums = [4,2,3,4]
Output: 4
*/

int triangleNumber(vector<int>& nums) {
    int n = nums.size();
    int k = n-1;
    int ans = 0;
    
    sort(nums.begin(), nums.end());
    
    while (k > 1) {
        int i = 0, j = k-1;
        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                ans += (j-i);
                j--;
            } else {
                i++;
            }
        }
        k--;
    }
    return ans;
}
