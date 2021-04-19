/*
An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

Write a function:

vector<int> solution(vector<int> &A, int K);

that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.
*/

void reverse(vector<int>& A, int i, int j)
{
	while (i < j) {
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
		i++;
		j--;
	}
}

vector<int> solution(vector<int> &A, int k) {
	int n = A.size();

	if (n == 1 || n == 0 || n == k)
		return A;

	if (k > n) k %= n;

	reverse(A, 0, n - k - 1);
	reverse(A, n - k, n-1);
	reverse(A, 0, n-1);
	return A;
}
