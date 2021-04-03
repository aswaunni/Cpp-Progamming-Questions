/*
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i
Example 2:

Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole
string , the input string becomes
mno.pqr
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	string s = "i.like.this.program.very.much";

	vector<string> sv;
	string str;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '.') {
			sv.push_back(str);
			str = "";
		} else
			str += s[i];
	}
	sv.push_back(str);

	for (int i = sv.size() -1; i > 0; i--)
		cout << sv[i] << ".";

	cout << sv[0];

	return 0;
}
