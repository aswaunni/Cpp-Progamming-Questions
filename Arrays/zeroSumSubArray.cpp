/*
   Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

   Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
 sum 0 will be -2 2 -8 1 7.

Solution:
Let's now try to improve the time complexity by taking an extra space of 'n' length. The new array will store the sum of all the elements up to that index. The sum-index pair will be stored in a hash-map. A Hash map allows insertion and deletion of key-value pair in constant time. Therefore, the time complexity remains unaffected. So, if the same value appears twice in the array, it will be guaranteed that the particular array will be a zero-sum sub-array. 
 */

int maxLen(int A[], int n)
{
	int result;
	unordered_map<int, int> m;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += A[i];

		if (sum == 0)
			result = i + 1;

		if (m.find(sum) != m.end())
			result = max(result, i - m[sum]);
		else
			m[sum] = i;
	}
	return result;
}
