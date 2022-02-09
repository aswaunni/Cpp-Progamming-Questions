/*
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
*/

#include <bits/stdc++.h>

using namespace std;

//Method 1
int recur(string s, int i, int n) {
	int result;
	if (n == i) {
		return 1;
	}

	if (s[i] != '0')
		result += recur(s, i+1, n);
	if ((i+1) < n && (s[i] == '1' || s[i] == '2' && s[i+1] < '7'))
		result += recur(s, i+2, n);

	return result;
}

// Method 2 -> Dynamic Programming

int recur(string s, int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    
    for (int i = 0; i < n; i++) {
        if (s[i] != '0')
            dp[i+1] += dp[i];
        if (i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')))
            dp[i+1] += dp[i-1];
    }
    return dp[n];
}

int main()
{
	string in = "1111";
	cout << recur(in, in.length());

	return 0;
}
