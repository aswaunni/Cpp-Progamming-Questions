/*
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

int maxProduct(vector<int>& nums) {
    int ans = INT_MIN;
    int n = nums.size();
    
    int l = 1, r = 1;
    for (int i = 0; i < n; i++) {
        l *= nums[i];
        r *= nums[n - 1 - i];
        ans = max(ans, max(l, r));
        
        if (l == 0) l = 1;
        if (r == 0) r = 1;
    }
    return ans;
}

//OR

int maxProduct(vector<int>& nums) {        
    int n = nums.size();
    
    int ans = nums[0];
    int mx = nums[0];
    int mn = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] < 0)
            swap(mx, mn);
        
        mx = max(nums[i], mx*nums[i]);
        mn = min(nums[i], mn*nums[i]);
        
        ans = max(ans, mx);
    }
    return ans;
}
