/*
Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

Example 1:

Input:
N = 5, K = 3
A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
Explanation: Sum of 0, 0, 1, 2 is equal
to K.
Example 2:

Input:
N = 7, K = 23
A[] = {10,2,3,4,5,7,8}
Output: 2 3 8 10 $2 4 7 10 $3 5 7 8 $
Explanation: Sum of 2, 3, 8, 10 = 23,
sum of 2, 4, 7, 10 = 23 and sum of 3,
5, 7, 8 = 23.
*/

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    
    for (int l = n-1; l >= 3; --l) {
        if (l < n-1 && nums[l] == nums[l+1]) continue;
        for (int k = l-1; k >= 2; --k) {
            if (k < l-1 && nums[k] == nums[k+1]) continue;
            int i = 0, j = k-1;
            while (i < j) {
                int s1 = nums[i] + nums[j], s2 = nums[k] + nums[l];
                if (s1 < target - s2) {
                    i++;
                } else if (s1 > target - s2) {
                    j--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    do {++i;} while(nums[i] == nums[i-1] && i < j);
                    do {--j;} while(nums[j] == nums[j+1] && i < j);
                }
            }
        }
    }
    return ans;
    
}
