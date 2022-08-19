/*
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/


int removeDuplicates(vector<int>& nums) {
    int i = 0;
    
    for (auto a : nums) {
        if (i < 2 || a > nums[i-2])
            nums[i++] = a;
    }
    return i;
}

// OR

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    int cnt= 0;
    
    for (int j = 0; j < nums.size(); j++) {
        nums[i] = nums[j];
        
        if (i > 0 && nums[i] == nums[i-1])
            cnt++;
        else
            cnt = 1;
        
        if (cnt <= 2)
            i++;
    }
    return i;
}
