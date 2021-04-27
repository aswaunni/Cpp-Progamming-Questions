/*
Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

Example 1:

Input:
N = 5, K = 3
A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
Explanation: Sum of 0, 0, 1, 2 is equal
to K.
Example 2:

Input:
N = 7, K = 23
A[] = {10,2,3,4,5,7,8}
Output: 2 3 8 10 $2 4 7 10 $3 5 7 8 $
Explanation: Sum of 2, 3, 8, 10 = 23,
sum of 2, 4, 7, 10 = 23 and sum of 3,
5, 7, 8 = 23.
*/

vector<vector<int> > fourSum(vector<int> &A, int X) {
	sort(A.begin(), A.end());

	int n = A.size();
	vector<vector<int> > result;

	int l, r;


	for (int i = 0; i < n - 3; i++)
	{
		for (int j = i+1; j < n - 2; j++)
		{
			l = j + 1;
			r = n-1;

			while (l < r)
			{
				if( A[i] + A[j] + A[l] + A[r] == X)
				{
					vector<int> v;
					v.push_back(A[i]);
					v.push_back(A[j]);
					v.push_back(A[l]);
					v.push_back(A[r]);
					result.push_back(v);
					l++; r--;
				}
				else if (A[i] + A[j] + A[l] + A[r] < X)
					l++;
				else
					r--;
			}   
		} 
	}

	return result;
}
