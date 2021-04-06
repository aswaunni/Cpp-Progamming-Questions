/*
Your task is to implement the function strstr. The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the string s. The function returns and integer denoting the first occurrence of the string x in s (0 based indexing).

 

 Example 1:

 Input:
 s = GeeksForGeeks, x = Fr
 Output: -1
 Explanation: Fr is not present in the
 string GeeksForGeeks as substring.
  

  Example 2:

  Input:
  s = GeeksForGeeks, x = For
  Output: 5
  Explanation: For is present as substring
  in GeeksForGeeks from index 5 (0 based
  indexing).

*/

#include <bits/stdc++.h>
using namespace std;

int strstr(string s, string x)
{
	int n = s.length();
	int m = x.length();

	for (int i = 0; i < n; i++) {
		if (s[i] == x[0]) {
			if (i + m - 1 < n) {
				if (s.substr(i, m) == x)
					return i;
			}
		}
	}
	return -1;
}

int main() {
	string s = "GeeksForGeeks";
	string x = "For";

	cout << strstr(s, x);

	return 0;
}

