/*
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
*/

#include <bits/stdc++.h>

using namespace std;

//Method 1
int recur(string in, int n) {
	int result;
	if (n == 0) {
		cout << "\n";
		return 1;
	}

	int start = in.length() - n;
	result = recur(in, n-1);
	if (stoi(in.substr(start, 2)) <= 26 && n >= 2) {
		result += recur(in, n-2);
	}
	return result;
}

//Method 2
int recur(string in, int start, int n) {
	int result;
	if (n == start) {
		return 1;
	}

	result = recur(in, start+1, n);
	if (stoi(in.substr(start, 2)) <= 26 && (n-start) >= 2)
		result += recur(in, start+2, n);

	return result;
}

int main()
{
	string in = "1111";
	cout << recur(in, in.length());

	return 0;
}
