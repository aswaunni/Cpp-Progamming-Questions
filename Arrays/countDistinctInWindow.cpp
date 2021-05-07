/*
Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
*/

vector <int> countDistinct (int A[], int n, int k)
{
	map<int, int> m;
	int count = 0;
	vector<int> result;

	int i;
	for(i = 0; i < k; i++) {
		if (m[A[i]] == 0)
			count++;

		m[A[i]]++;
	}
	result.push_back(count);

	for (; i < n; i++) {

		m[A[i-k]]--;
		if (m[A[i-k]] == 0)
			count--;

		if (m[A[i]] == 0)
			count++;
		m[A[i]]++;

		result.push_back(count);
	}
	return result;
}
