/*
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

 

Example 1:

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
Example 2:

Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.
*/

int longestMountain(vector<int>& arr) {
    int n = arr.size();
    
    int i = 0;
    int ans = 0;
    
    while (i < n-1) {
        int incr = 0, decr = 0;
        
        while (i < n-1 && arr[i] < arr[i+1]) ++i, ++incr;
        
        while (i < n-1 && arr[i] > arr[i+1]) ++i, ++decr;
        
        if (incr && decr)
            ans = max(ans, incr + decr + 1);
        
        while (i < n-1 && arr[i] == arr[i+1]) ++i;
    }
    return ans;
}

// OR

int longestMountain(vector<int>& arr) {
    int n = arr.size();
    
    vector<int> up(n, 0), down(n, 0);
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] > arr[i+1])
            down[i] = down[i+1] + 1;
    }
    
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i-1])
            up[i] = up[i-1] + 1;
        if (up[i] && down[i])
            ans = max(ans, up[i] + down[i] + 1);
    }
    return ans;
}
	
