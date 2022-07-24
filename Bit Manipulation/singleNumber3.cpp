/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
 
 */

vector<int> singleNumber(vector<int>& nums) {
    long x = 0;
    
    for (auto& a : nums)
        x ^= a;
    
    x &= -x; // get last set bit
    
    int y = 0, z = 0;
    for (auto& a : nums) { //divide into 2 groups based on if bit set or not
        if (a&x)
            y ^= a;
        else
            z ^= a;
    }
    return {y, z};
}
