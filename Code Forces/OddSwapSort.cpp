/*
You are given an array a1,a2,…,an. You can perform operations on the array. In each operation you can choose an integer i (1≤i<n), and swap elements ai and ai+1 of the array, if ai+ai+1 is odd.

Determine whether it can be sorted in non-decreasing order using this operation any number of times.

Input
Each test contains multiple test cases. The first line contains a single integer t (1≤t≤105) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤105) — the length of the array.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the elements of the array.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, print "Yes" or "No" depending on whether you can or can not sort the given array.

You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as positive answer).

Example
inputCopy
4
4
1 6 31 14
2
4 2
5
2 9 6 7 10
3
6 6 6
outputCopy
Yes
No
No
Yes
*/

// HINT : Odd and even elements should be sorted

#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main ()
{
	ios::sync_with_stdio(false);
    int t;
	cin >> t;
	
	while (t--) {
        int n;
		cin >> n;
		
		bool ans = true;
		int o = -1, e = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			
			if (x%2 == 0) {
			    if (x < e) ans = false;
			    e = x;
			} else {
			    if (x < o)  ans = false;
			    o = x;
			}
		}
		
		cout << (ans ? "YES": "NO") << "\n";
		
	}
	return 0;
}
