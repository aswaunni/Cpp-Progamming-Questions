/*
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).

NOTE: Required Time Complexity O(n2).

Input:
The first line of input consists number of the testcases. The following T lines consist of a string each.

Output:
In each separate line print the longest palindrome of the string given in the respective test case.

Constraints:
1 ≤ T ≤ 100
1 ≤ Str Length ≤ 104

Example:
Input:
1
aaaabbaa

Output:
aabbaa
*/

#include <bits/stdc++.h>
using namespace std;
string palindrome(string s)
{
	int maxLength = 1;
	int start = 0;;
	int n = s.length();

	int l, h;

	for (int i = 1; i < n; i++) {
		l = i-1;
		h = i;
		while (l >=0 && h < n && s[l] == s[h]) {
			if (h - l + 1 > maxLength) {
				maxLength = h - l + 1;
				start = l;
			}
			--l;
			++h;
		}

		l = i-1;
		h = i+1;
		while (l >=0 && h < n && s[l] == s[h]) {
			if (h - l + 1 > maxLength) {
				maxLength = h - l + 1;
				start = l;
			}
			--l;
			++h;
		}
	}

	return s.substr(start, maxLength);

}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		cout << palindrome(s).c_str() << "\n";
	}

	return 0;
}
