/*
*/

#include <bits/stdc++.h>
using namespace std;

int atoi(string s)
{
	int n = s.length();
	if (n == 0)
		return -1;

	int result = 0;
	int sign = 1;
	int i =0;

	if (s[0] == '-') {
		sign = -1;
		i++;
	}

	for (; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			result = ((result*10) + s[i] - '0');
		} else {
			return -1;
		}
	}
	return sign*result;
}

int main() {
	string s = "-123";

	cout << atoi(s);

	return 0;
}

