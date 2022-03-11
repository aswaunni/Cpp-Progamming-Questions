/*
There is a classroom with two rows of computers. There are n computers in each row and each computer has its own grade. Computers in the first row has grades a1,a2,…,an and in the second row — b1,b2,…,bn.

Initially, all pairs of neighboring computers in each row are connected by wire (pairs (i,i+1) for all 1≤i<n), so two rows form two independent computer networks.

Your task is to combine them in one common network by connecting one or more pairs of computers from different rows. Connecting the i-th computer from the first row and the j-th computer from the second row costs |ai−bj|.

You can connect one computer to several other computers, but you need to provide at least a basic fault tolerance: you need to connect computers in such a way that the network stays connected, despite one of its computer failing. In other words, if one computer is broken (no matter which one), the network won't split in two or more parts.

That is the minimum total cost to make a fault-tolerant network?

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases. Next t cases follow.

The first line of each test case contains the single integer n (3≤n≤2⋅105) — the number of computers in each row.

The second line contains n integers a1,a2,…,an (1≤ai≤109) — the grades of computers in the first row.

The third line contains n integers b1,b2,…,bn (1≤bi≤109) — the grades of computers in the second row.

It's guaranteed that the total sum of n doesn't exceed 2⋅105.

Output
For each test case, print a single integer — the minimum total cost to make a fault-tolerant network.

Example
inputCopy
2
3
1 10 1
20 4 25
4
1 1 1 1
1000000000 1000000000 1000000000 1000000000
outputCopy
31
1999999998
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N = 1e9;	
 
void solve() {
    int n;
	cin>>n;
	vector<ll>a(n), b(n);
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<n;++i) cin>>b[i];
	
	ll ans=1e10;
	ans=min(ans, abs(a[0]-b[0])+abs(a[n-1]-b[n-1]));
	ans=min(ans, abs(a[0]-b[n-1])+abs(a[n-1]-b[0]));
	ll min1=1e10, min2=1e10, min3=1e10, min4=1e10;
	for(int i=0;i<n;++i)
	{
		min1=min(min1, abs(a[0]-b[i]));
		min2=min(min2, abs(a[n-1]-b[i]));
		min3=min(min3, abs(b[0]-a[i]));
		min4=min(min4, abs(b[n-1]-a[i]));
	}
	ans=min(ans, abs(a[0]-b[0])+min2+min4);
	ans=min(ans, abs(a[n-1]-b[n-1])+min1+min3);
	ans=min(ans, abs(a[0]-b[n-1])+min2+min3);
	ans=min(ans, abs(a[n-1]-b[0])+min1+min4);
	ans=min(ans, min1+min2+min3+min4);
	cout<<ans<<'\n';
}

int main () {
    FIO
    int t;
	cin >> t;
	
	while (t--) {
        solve();
	}
}
