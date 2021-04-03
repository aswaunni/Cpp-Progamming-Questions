/*
   You are given an integer n. In one move, you can either multiply n by two or divide n by 6 (if it is divisible by 6 without the remainder).
   Your task is to find the minimum number of moves needed to obtain 1 from n or determine if it's impossible to do that.
   You have to answer t independent test cases.
   Input
   The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow.
   The only line of the test case contains one integer n (1≤n≤109).
   Output
   For each test case, print the answer — the minimum number of moves needed to obtain 1 from n if it's possible to do that or -1 if it's impossible to obtain 1 from n.
   Example
   inputCopy
   7
   1
   2
   3
   12
   12345
   15116544
   387420489
   outputCopy
   0
   -1
   2
   -1
   -1
   12
   36
 */

#include <bits/stdc++.h>

using namespace std;


int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		int ex = 0, count = 0;
		while (m > 1) {	
			if (m%2 == 0) {
				if (m%6 != 0) {
					ex = 1;
					break;
				}
				m /= 6;
			} else
				m*= 2;
			count++;
		}
		if (ex == 1)
			cout << "-1\n";
		else
			cout << count << "\n";
	}

	return 0;
}
