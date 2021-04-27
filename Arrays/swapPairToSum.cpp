/*
   Given two arrays of integers A[] and B[] of size N and M, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.



   Example 1:

Input: N = 6, M = 4
A[] = {4, 1, 2, 1, 1, 2}
B[] = (3, 6, 3, 3)
Output: 1
Explanation: Sum of elements in A[] = 11
Sum of elements in B[] = 15, To get same 
sum from both arrays, we can swap following 
values: 1 from A[] and 3 from B[]

Solution:

We are looking for two values, a and b, such that: 
sumA - a + b = sumB - b + a
2a - 2b  = sumA - sumB
a - b  = (sumA - sumB) / 2
Therefore, we’re looking for two values that have a specific target difference: (sumA – sumB) / 2.

Sort the arrays.
Traverse both array simultaneously and do following for every pair.
If the difference is too small then, make it bigger by moving ‘a’ to a bigger value.
If it is too big then, make it smaller by moving b to a bigger value.
If it’s just right, return this pair.
 */

int findSwapValues(int A[], int n, int B[], int m)
{
	int sum1 = accumulate(A, A+n, 0);
	int sum2 = accumulate(B, B+m, 0);
	if ((sum1-sum2)%2)
		return -1;

	int target = (sum1-sum2)/2;

	sort(A, A+n);
	sort(B, B+n);

	int i = 0, j = 0;
	while (i < n && j < m) {
		int diff = A[i] - B[j];

		if (diff == target)
			return 1;
		else if (diff < target)
			i++;
		else
			j++;
	}
	return -1;
}
