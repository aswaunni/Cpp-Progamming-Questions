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


// First, if there's no zero in the array, then the subarray with maximum product must start with the first element or end with the last element. 
// And therefore, the maximum product must be some prefix product or suffix product. 
//So in this solution, we compute the prefix product A and suffix product B, and simply return the maximum of A and B.

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

// OR

int maxProduct(vector<int>& nums) {
    int ans = INT_MIN, l = 0, r = 0;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        l = (l ? l : 1) * nums[i];
        r = (r ? r : 1) * nums[n-1-i];
        
        ans = max(ans, max(l, r));
    }
    return ans;
}

