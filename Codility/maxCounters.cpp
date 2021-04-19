/*
   You are given N counters, initially set to 0, and you have two possible operations on them:

   increase(X) − counter X is increased by 1,
   max counter − all counters are set to the maximum value of any counter.
   A non-empty array A of M integers is given. This array represents consecutive operations:

   if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
   if A[K] = N + 1 then operation K is max counter.
   For example, given integer N = 5 and array A such that:

   A[0] = 3
   A[1] = 4
   A[2] = 4
   A[3] = 6
   A[4] = 1
   A[5] = 4
   A[6] = 4
   the values of the counters after each consecutive operation will be:

   (0, 0, 1, 0, 0)
   (0, 0, 1, 1, 0)
   (0, 0, 1, 2, 0)
   (2, 2, 2, 2, 2)
   (3, 2, 2, 2, 2)
   (3, 2, 2, 3, 2)
   (3, 2, 2, 4, 2)
   The goal is to calculate the value of every counter after all operations.

   Write a function:

   vector<int> solution(int N, vector<int> &A);

   that, given an integer N and a non-empty array A consisting of M integers, returns a sequence of integers representing the values of the counters.

   Result array should be returned as a vector of integers.
 */

vector<int> solution(int N, vector<int> &A) {
	int global_count = 0, max_count = 0;
	vector<int> res(N, 0);

	for (auto& a : A) {
		int index = a-1;
		if (a >= 1 && a <= N) {
			res[index] = (max(global_count, res[index]) + 1);
			max_count = max(max_count, res[index]); 
		} else if (a == N+1)
			global_count = max(global_count, max_count);
	}

	for(int i = 0; i < N; i++)
		res[i] = max(global_count, res[i]);

	return res;
}
