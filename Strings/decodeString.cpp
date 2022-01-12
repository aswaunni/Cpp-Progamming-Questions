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
