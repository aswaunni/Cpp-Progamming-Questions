/*
iven an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
*/

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> q;
    
    for (auto& a : nums) {
        if (q.size() < k)
            q.push(a);
        else {
            if (q.top() < a) {
                q.pop();
                q.push(a);
            }
        }
    }
    return q.top();
}

//OR

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    int l = left+1, r = right;
    
    while (l <= r) {
        if (nums[l] < pivot && nums[r] > pivot)
            swap(nums[l++], nums[r--]);
        
        if (nums[l] >= pivot)
            l++;
        if (nums[r] <= pivot)
            r--;
    }
    swap(nums[left], nums[r]);
    return r;
}

int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size()-1;
    int ans;
    
    while (true) {
        int pivot = partition(nums, l, r);
        
        if (pivot == k-1) {
            ans = nums[pivot];
            break;
        }
        
        if (pivot < k-1)
            l = pivot+1;
        else
            r = pivot-1;
    }
    return ans;
}
