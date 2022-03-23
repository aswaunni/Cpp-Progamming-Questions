/*
You are given two arrays A and B, each of size N. You can perform the following types of operations on array A.

Type 1: Select any prefix of A and increment all its elements by 1.
Type 2: Select any suffix of A and increment all its elements by 1.
Your task is to transform the array A into array B using the minimum number of operations. If it is impossible to do so, output −1.

For an array A having N elements:

A prefix of the array A is a subarray starting at index 1.
A suffix of the array A is a subarray ending at index N.
Input Format
First line will contain T, number of test cases. Then the test cases follow.
The first line of each test case contains a single integer N, the size of arrays A and B.
The next line contains N space-separated integers, where the ith integer denotes Ai.
The next line contains N space-separated integers, where the ith integer denotes Bi.
Output Format
For each test case, print a single line containing one integer ― minimum operations required to convert A into B. Print −1 if it is impossible to convert A into B.

Constraints
1≤T≤104
1≤N≤105
−1014≤Ai,Bi≤1014
Sum of N over all test cases does not exceed 2⋅105.
Sample Input 1 
3
5
2 3 5 1 2
4 3 6 2 3
4
0 0 0 0
1 2 2 1
3
1 2 3
1 2 2
Sample Output 1 
3
2
-1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N = 2e5+5;	
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

ll x[N], y[N], vis[N], ansx[N], ansy[N];
 
void solve() {
    ll n;
    cin >> n;
    
    vector<ll> a(n), d(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        d[i] = x - a[i];
    }
    
    if (d[0] < 0 || d[n-1] < 0) {
        cout << -1 << endl;
        return;
    }
    
    ll x1 = d[0], x2 = 0;
    ll res1 = 0, res2 = 0;
    for (ll i = 0; i < n; i++) {
        if (d[i] > (x1 + x2)) {
            x2 += (d[i] - x1 - x2);
        } else if (d[i] < (x1 + x2)) {
            x1 -= (x1 + x2 - d[i]);
        }
        
        if (x1 < 0) {
            cout << -1 << endl;
            return;
        }
        res1 = max(res1, x1);
        res2 = max(res2, x2);
    }
    cout << res1 + res2 << endl;
}

int main () {
    FIO
	int t;
	cin >> t;
	while (t--)
		solve();

}
