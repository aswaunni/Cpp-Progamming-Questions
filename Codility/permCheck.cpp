/*
   A non-empty array A consisting of N integers is given.

   A permutation is a sequence containing each element from 1 to N once, and only once.

   For example, array A such that:

   A[0] = 4
   A[1] = 1
   A[2] = 3
   A[3] = 2
   is a permutation, but array A such that:

   A[0] = 4
   A[1] = 1
   A[2] = 3
   is not a permutation, because value 2 is missing.

   The goal is to check whether array A is a permutation.

   Write a function:

   int solution(vector<int> &A);

   that, given an array A, returns 1 if array A is a permutation and 0 if it is not.
 */

int solution(vector<int> &A) {
	auto minMax = minmax_element(A.begin(), A.end());
	int mini = *minMax.first;
	int maxi = *minMax.second;
	int n = A.size();

	if (mini != 1 || ((maxi - mini + 1) != n))
		return 0;

	for (int i = 0; i < n; i++) {
		int j = 0;

		if (A[i] < 0){
			j = -A[i] - mini;
		} else
			j = A[i] - mini;

		if (A[j] > 0) {
			A[j] = -A[j];
		} else
			return 0;
	}
	return 1;
}
