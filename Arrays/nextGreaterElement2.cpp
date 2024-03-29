/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
*/

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    
    stack<int> s;
    vector<int> ans(n, -1);
    
    for (int i = n-1; i >= 0; --i)
        s.push(nums[i]);
    
    for (int i = n-1; i >= 0; --i) {
        while (!s.empty() && nums[i] >= s.top())
            s.pop();
        ans[i] = s.empty() ? -1 : s.top();
        s.push(nums[i]);
    }
    return ans;
}

// OR

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    
    stack<int> s;
    vector<int> ans(n, -1);
    
    for (int i = 0; i < n*2; ++i) {
        while (!s.empty() && nums[i%n] > nums[s.top()]) {
            ans[s.top()] = nums[i%n];
            s.pop();
        }
        s.push(i%n);
    }
    return ans;
}
