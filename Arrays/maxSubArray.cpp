/*
Find out the maximum sub-array of non negative numbers from an array.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:
A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]

NOTE 1: If there is a tie, then compare with segment's length and return segment which has maximum length.
NOTE 2: If there is still a tie, then return the segment with minimum starting index.

Example 1:

Input:
N = 3
A[] = {1, 2, 3}
Output: 1 2 3
Explanation: In the given array every
element is non-negative.
Example 2:

Input:
N = 2
A[] = {-1, 2}
Output: 2
Explanation: The only subarray [2] is
the answer.
*/

vector<int> findSubarray(int a[], int n) {
    long long ans = 0;
    long long sum = 0;
    int x = 0;
    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0)
            sum += a[i];
        else {
            if (sum > ans) {
                start = x;
                end = i;
                ans = sum;
            }
            x = i+1;
            sum = 0;
        }
    }
        
    if (sum > ans) {
       start = x;
       end = n;
    }
    
    if (end == 0)
        return {-1};
        
    return vector<int>(a+start, a+end);
}
