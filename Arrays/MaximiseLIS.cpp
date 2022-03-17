/*
Maximise Longest increasing subsequence

Chef received an array A of N integers as a valentine's day present. He wants to maximize the length of the longest strictly increasing subsequence by choosing a subarray and adding a fixed integer X to all its elements.

More formally, Chef wants to maximize the length of the longest strictly increasing subsequence of A by performing the following operation at most once:

Pick 3 integers L,R and X (1≤L≤R≤N, X∈Z) and assign Ai:=Ai+X ∀ i∈[L,R].
Find the length of the longest strictly increasing sequence Chef can obtain after performing the operation at most once.

Input Format
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains one integer N, the size of the array.
The next line contains N space-separated integers, where the ith integer denotes Ai.
Output Format
For each test case, print a single line containing one integer ― the length of the longest strictly increasing sequence Chef can obtain.

Constraints
1≤T≤103
1≤N≤2×105
1≤Ai≤109
Sum of N over all test cases does not exceed 2⋅105.
Sample Input 1 
3
3
1 2 1
5
1 5 8 6 9
4
1 2 2 1
Sample Output 1 
3
5
3
*/

#include "bits/stdc++.h"
using namespace std;
 
#define all(x)      x.begin(), x.end()
 
void solve() {
	// INPUT
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
 
	// lis stores the current lis
	// pref stores the longest increasing subsequence till i
	vector<int> lis, pref(n);
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(all(lis), v[i]) - lis.begin();
		if (it == lis.size()) lis.push_back(v[i]);
		else lis[it] = v[i];
		pref[i] = lis.size();
	}
 
	lis.clear();
	// suff stores the longest increasing subsequence starting from i
	vector<int> suff(n);
	for (int i = n - 1; i >= 0; i--) {
		auto it = lower_bound(all(lis), -v[i]) - lis.begin();
		if (it == lis.size()) lis.push_back(-v[i]);
		else lis[it] = -v[i];
		suff[i] = lis.size();
	}
 
	int ans = suff[0];
	for (int i = 1; i < n; i++) {
		ans = max(ans, suff[i] + pref[i - 1]);
	}
	cout << ans;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
		cout << '\n';
	}
	return 0;
}
