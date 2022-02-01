/*
You have an array of integers a of size n. Initially, all elements of the array are equal to 1. You can perform the following operation: choose two integers i (1≤i≤n) and x (x>0), and then increase the value of ai by ⌊aix⌋ (i.e. make ai=ai+⌊aix⌋).

After performing all operations, you will receive ci coins for all such i that ai=bi.

Your task is to determine the maximum number of coins that you can receive by performing no more than k operations.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases.

The first line of each test case contains two integers n and k (1≤n≤103;0≤k≤106) — the size of the array and the maximum number of operations, respectively.

The second line contains n integers b1,b2,…,bn (1≤bi≤103).

The third line contains n integers c1,c2,…,cn (1≤ci≤106).

The sum of n over all test cases does not exceed 103.

Output
For each test case, print one integer — the maximum number of coins that you can get by performing no more than k operations.

Example
inputCopy
4
4 4
1 7 5 2
2 6 5 2
3 0
3 5 2
5 4 7
5 9
5 2 5 6 3
5 9 1 9 7
6 14
11 4 6 2 8 16
43 45 9 41 15 38
outputCopy
9
0
30
167
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 1000;
int dp[N+1];

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	fill(dp, dp+N+1, 1e9);
	dp[1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (i+i/j <= N)
				dp[i+i/j] = min(dp[i+i/j], dp[i]+1);
		}
	}
	
	int t;
	cin >> t;
	
	while (t--) {
        int n, k;
		cin >> n >> k;
    
		vector<int> b(n), ans(k+1);
		int count = 0;
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			count += dp[b[i]];
		}

		k = min(k, count);
		for (int i = 0, c; i < n; i++) {
			cin >> c;
			for (int j = k; j >= dp[b[i]]; j--)
				ans[j] = max(ans[j], ans[j - dp[b[i]]] + c);
		}
		cout << ans[k] << "\n";
	}
	return 0;
}
