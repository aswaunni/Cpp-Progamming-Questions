/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

Write a function:

int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

*/
int solution(int N) {

	while (N%2 == 0) N /= 2; // to find trailing zeroes

	int m = 0, so_far = 0;;

	while (N > 0) {
		int x = N%2;

		if (x == 1) {
			m = max(m, so_far);
			so_far = 0;
		} else if (x == 0) {
			so_far++;
		}
		N /= 2;
	}
	return m;
}
