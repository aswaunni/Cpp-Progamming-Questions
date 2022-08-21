/*
Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

Example 1:

Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
*/

// Segment Tree Concept

class SegmentTreeNode {
public:
    int L;
    int R;
    int val;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    
    SegmentTreeNode(vector<int>& nums, int l, int r)
        : left(NULL)
        , right (NULL)
        , L(l)
        , R(r)
    {
        if (L == R)
            val = nums[L];
        else {
            int mid = (L+R)/2;
            left = new SegmentTreeNode(nums, L, mid);
            right = new SegmentTreeNode(nums, mid+1, R);
            val = left->val+ right->val;
        }
    }
    
    void update(int index, int new_val) {
        if (L == R)
            val = new_val;
        else {
            int mid = (L+R)/2;
            if (index <= mid)
                left->update(index, new_val);
            else
                right->update(index, new_val);
            val = left->val+ right->val;
        }
    }
    
    int sumRange(int l, int r) {
        if (l > r)
            return 0;
        if (L == l && R == r)
            return val;
        
        int mid = (L+R)/2;
        return left->sumRange(l, min(r, mid)) + right->sumRange(max(l, mid+1), r);
    }
};

class NumArray {
public:
    SegmentTreeNode* tree;
    
    NumArray(vector<int>& nums) {
        tree = new SegmentTreeNode(nums, 0, nums.size()-1);
    }
    
    void update(int index, int val) {
        tree->update(index, val);
    }
    
    int sumRange(int left, int right) {
        return tree->sumRange(left, right);
    }
};
