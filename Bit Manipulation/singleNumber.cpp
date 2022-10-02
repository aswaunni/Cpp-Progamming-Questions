/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
*/

int singleNumber(int arr[], int n) 
{
    int ans = 0;
    for (int i = 0; i < 64; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += ((arr[j] & (1 << i)) != 0);
        ans = (ans | (sum%3)<<i);
    }
    return ans;
}

//OR

int singleNumber(vector<int>& nums) {
    int one = 0, two = 0, three = 0;
    for (int i = 0; i < nums.size(); ++i) {
        two |= one & nums[i];
        one ^= nums[i];
        three = one & two;
        one = one ^ three;
        two = two ^ three;
    }
    return one;
}

// OR

int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int i = 0; i < nums.size(); i++) {
        ones = (ones^nums[i]) & ~twos;
        twos = (twos^nums[i]) & ~ones;
    }
    return ones;
}
