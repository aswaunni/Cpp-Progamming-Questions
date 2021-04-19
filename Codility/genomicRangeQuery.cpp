/*
   A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?

   The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).

   For example, consider string S = CAGCCTA and arrays P, Q such that:

   P[0] = 2    Q[0] = 4
   P[1] = 5    Q[1] = 5
   P[2] = 0    Q[2] = 6
   The answers to these M = 3 queries are as follows:

   The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
   The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
   The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.
   Write a function:

   vector<int> solution(string &S, vector<int> &P, vector<int> &Q);

   that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M integers specifying the consecutive answers to all queries.

   Result array should be returned as a vector of integers.

   For example, given the string S = CAGCCTA and arrays P, Q such that:

   P[0] = 2    Q[0] = 4
   P[1] = 5    Q[1] = 5
   P[2] = 0    Q[2] = 6
   the function should return the values [2, 4, 1], as explained above.
 */

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {

	struct counter {
		int A = 0;
		int C = 0;
		int G = 0;
	};

	int n = S.length();
	int m = P.size();

	vector<int> result(m);
	vector<counter> vc;
	counter c;

	for (int i = 0; i <= n; i++) {
		vc.push_back(c);
		switch(S[i]) {
			case 'A' : {c.A++; break;}
			case 'C' : {c.C++; break;}
			case 'G' : {c.G++; break;}
		}
	}


	for (int i = 0; i < m; i++) {
		int from = P[i], to = Q[i]+1;
		if (vc[to].A - vc[from].A > 0)
			result[i] = 1;
		else if (vc[to].C - vc[from].C > 0)
			result[i] = 2;
		else if (vc[to].G - vc[from].G > 0)
			result[i] = 3;
		else
			result[i] = 4;
	}
	return result;
}
