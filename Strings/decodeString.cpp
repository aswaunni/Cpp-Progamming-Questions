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

// Method 3 -> Dynamic Programming

int CountWays(string s){
    if (s[0] == '0')
        return 0;
       
    int n = s.length();
    int mod = 1e9 + 7;
    vector<int> dp(n+1);
    
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
            
        int c1 = 0, c2 = 0;
        
        if (s[i-1] != '0')
            c1 = dp[i-1];
        
        if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7'))
            c2 = dp[i-2];
            
       dp[i] = (c1 + c2)%mod;
    }
    return dp[n];    
}

int main()
{
	string in = "1111";
	cout << recur(in, in.length());

	return 0;
}
