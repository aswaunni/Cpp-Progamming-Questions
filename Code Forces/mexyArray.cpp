/*
You are given an array B containing N integers, each of which is either −1 or a non-negative integer. Construct any integer array A of length N such that:

0≤Ai≤109 for every 1≤i≤N
If Bi≥0, A must satisfy mex(A1,A2,…,Ai)=Bi
Otherwise, Bi=−1, which means there is no constraint on mex(A1,A2,…,Ai)
If there does not exist any array satisfying the constraints, print −1 instead.

Note: The mex of a set of non-negative integers is the smallest non-negative integer that does not belong to it. For example, mex(1,2,3)=0,mex(0,2,4,1)=3, and mex(0,0,0)=1.

Input Format
The first line of input contains an integer T, denoting the number of testcases. The description of T testcases follows.
The first line of each testcase contains a single integer N.
The second line of each testcase contains N space-separated integers B1,B2,…,BN.
Output Format
For each testcase, output the required answer on a new line: −1 if no valid array exists, or N space-separated integers denoting the elements of any valid array A. The elements of A must satisfy 0≤Ai≤109.

Constraints
1≤T≤104
1≤N≤105
−1≤Bi≤105
The sum of N across all testcases won't exceed 2⋅105.
Sample Input 1 
2
7
0 -1 2 -1 5 -1 -1
3
2 -1 -1
Sample Output 1 
1 3 0 4 2 6 5
-1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve() {
    ll n;
    cin >> n;
    bool flag = true;
    
    vector<ll> a(n);
    ll last = -1;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != -1) {
            if (a[i] > (i+1))
                flag = false;
            else if (last != -1 && a[i] < a[last])
                flag = false;
            last = i;
        }
    }
    
    if (!flag) {
        cout << -1 << endl;
        return;
    }
    
    vector<ll> ans(n);
    for (ll i = 0; i < n; i++) ans[i] = i;
    
    if (a[n-1] != -1 && a[n-1] < n)
        ans[a[n-1]] = a[n-1] + 1;
        
    for (ll i = n-2; i >= 0; i--) {
        if (a[i] != -1 && a[i] <= ans[i])
            swap(ans[a[i]],ans[i+1]);
    }
    
    for (ll i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main () {
    FIO
	int t;
	cin >> t;
	while (t--)
		solve();

}
