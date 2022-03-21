/*
You are given a string S consisting of characters 0, 1, and ?. You can replace each ? with either 0 or 1. Your task is to find if it is possible to assign each ? to either 0 or 1 such that the resulting string has no substrings that are palindromes of length 5 or more.

Input
The first line of the input gives the number of test cases, T. T test cases follow.

Each test case consists of two lines.
The first line of each test case contains an integer N, denoting the length of the string S.
The second line of each test case contains a string S of length N.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is POSSIBLE if there is a possible resulting string that has no palindromic substrings of length 5 or more, or IMPOSSIBLE otherwise.

Limits
Memory limit: 1 GB.
1≤T≤100.
S only consists of characters 0, 1 and ?.

Test Set 1
Time limit: 20 seconds.
1≤N≤15.
Test Set 2
Time limit: 90 seconds.
1≤N≤5×104.
Sample
Sample Input
2
9
100???001
5
100??
Sample Output
Case #1: IMPOSSIBLE
Case #2: POSSIBLE
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N = 5e4+5;	
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

string s;
map<pair<int, string>, int> dp;

bool notPalindrome(string s) {
    string t = s;
    reverse(s.begin(), s.end());
    return s != t;
}

int isPossible(string prev, int i) {
    if (i == s.size())
        return 1;
        
    if (dp.count({i, prev}))
        return dp[{i, prev}];
    
    int ans = 0;
    string s1 = prev.substr(1, 4) + '0', s2 = prev.substr(1, 4) + '1';
    if (s[i] == '?') {
        if (notPalindrome(s1) && notPalindrome(prev + '0'))
            ans += isPossible(s1, i+1);
        if (notPalindrome(s2) && notPalindrome(prev + '1'))
            ans += isPossible(s2, i+1);
    } else if (s[i] == '0') {
        if (notPalindrome(s1) && notPalindrome(prev + '0'))
            ans += isPossible(s1, i+1);
    } else {
        if (notPalindrome(s2) && notPalindrome(prev + '1'))
            ans += isPossible(s2, i+1);
    }
    dp[{i, prev}] = ans;
    return ans;
}

void solve(int t) {
    int n;
    cin >> n;
    cout << "Case #" << t << ": ";

    cin >> s;
    dp.clear();
    cout << (isPossible("?????", 0) ? "POSSIBLE\n" : "IMPOSSIBLE\n");
}

int main () {
    FIO
    int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
      solve(i);
	}
}
