/*
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
*/

int countLessThan(vector<vector<int>>& mtx, int mid) {
    int n = mtx.size(), m = mtx[0].size();
    int r = 0, c = m-1;
    
    int cnt = 0;
    
    while (r < n && c >= 0) {
        while (r < n && mtx[r][c] <= mid) {
            cnt += c+1;
            ++r;
        }
        --c;
    }
    return cnt;
}

int kthSmallest(vector<vector<int>>& mtx, int k) {
    int n = mtx.size(), m = mtx[0].size();
    
    int l = mtx[0][0], r = mtx[n-1][m-1];
    
    while (l <= r) {
        int mid = (l+r)/2;
        
        if (countLessThan(mtx, mid) >= k) {
            r = mid-1;
        } else
            l = mid+1;
        }
    return l;
}
