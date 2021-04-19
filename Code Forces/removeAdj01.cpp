/*
Once he thought about a string of length n consisting of zeroes and ones. Consider the following operation: we choose any two adjacent positions in the string, and if one them contains 0, and the other contains 1, then we are allowed to remove these two digits from the string, obtaining a string of length n - 2 as a result.

Now Andreid thinks about what is the minimum length of the string that can remain after applying the described operation several times (possibly, zero)? Help him to calculate this number.

Input
First line of the input contains a single integer n (1 ≤ n ≤ 2·105), the length of the string that Andreid has.

The second line contains the string of length n consisting only from zeros and ones.

Output
Output the minimum length of the string that may remain after applying the described operations several times.

Examples
inputCopy
4
1100
outputCopy
0
inputCopy
5
01010
outputCopy
1
inputCopy
8
11101111
outputCopy
6
*/

#include <bits/stdc++.h>
using namespace std;

string removeAjd(string s, int n)
{
	if (n == 1)
		return s;
	int k = 0;
	int i;

	for(i = 1; i < n; i++) {
		if (s[i-1] == s[i]) {
			s[k++] = s[i-1];
		} else {
			i++;
		}

		if (i == n-1)
			s[k++] = s[i];
	}
	s[k] = '\0';

	if (k == 0 || i==k)
		return s;
	else
		s = removeAjd(s, k);

	return s;
}


int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	s = removeAjd(s, n);
	int i;
	for (i = 0; s[i]; ++i);

	cout << i;
	return 0;
}


