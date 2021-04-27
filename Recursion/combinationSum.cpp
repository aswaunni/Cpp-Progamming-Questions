/*
   Given an array of integers A[] of size N and a sum B, find all unique combinations in A where the sum is equal to B. Each number in A may only be used once in the combination.

Note:
All numbers will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.


Example 1:

Input: 
N = 7
A = {9, 1, 2, 7, 6, 1, 5}
B = 8
Output: (1 1 6)(1 2 5)(1 7)(2 6)
Explaination: These are the only possible 
combinations for getting sum 8.
 */

void findSum(vector<int> &A, int idx, int sum, vector<vector<int>>& result, vector<int>& r)
{
	if (sum == 0) {
		result.push_back(r);
		return;
	}

	if (sum < 0)
		return;

	for (int i = idx; i < A.size(); i++) {
		if (i > idx && A[i] == A[i-1]) continue; // To avoid same combinations
		r.push_back(A[i]);
		findSum(A, i+1, sum - A[i], result, r) ; //if numbers can be repeated findSum(A, i, sum - A[i], result, r)
		r.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int> &A, int N, int B){
	sort(A.begin(), A.end());

	vector<vector<int>> result;
	vector<int> r;
	findSum(A, 0, B, result, r);
	return result;
}
