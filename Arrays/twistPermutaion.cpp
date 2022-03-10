/*
Petya got an array a of numbers from 1 to n, where a[i]=i.

He performed n operations sequentially. In the end, he received a new state of the a array.

At the i-th operation, Petya chose the first i elements of the array and cyclically shifted them to the right an arbitrary number of times (elements with indexes i+1 and more remain in their places). One cyclic shift to the right is such a transformation that the array a=[a1,a2,…,an] becomes equal to the array a=[ai,a1,a2,…,ai−2,ai−1,ai+1,ai+2,…,an].

For example, if a=[5,4,2,1,3] and i=3 (that is, this is the third operation), then as a result of this operation, he could get any of these three arrays:

a=[5,4,2,1,3] (makes 0 cyclic shifts, or any number that is divisible by 3);
a=[2,5,4,1,3] (makes 1 cyclic shift, or any number that has a remainder of 1 when divided by 3);
a=[4,2,5,1,3] (makes 2 cyclic shifts, or any number that has a remainder of 2 when divided by 3).
Let's look at an example. Let n=6, i.e. initially a=[1,2,3,4,5,6]. A possible scenario is described below.

i=1: no matter how many cyclic shifts Petya makes, the array a does not change.
i=2: let's say Petya decided to make a 1 cyclic shift, then the array will look like a=[2,1,3,4,5,6].
i=3: let's say Petya decided to make 1 cyclic shift, then the array will look like a=[3,2,1,4,5,6].
i=4: let's say Petya decided to make 2 cyclic shifts, the original array will look like a=[1,4,3,2,5,6].
i=5: let's say Petya decided to make 0 cyclic shifts, then the array won't change.
i=6: let's say Petya decided to make 4 cyclic shifts, the array will look like a=[3,2,5,6,1,4].
You are given a final array state a after all n operations. Determine if there is a way to perform the operation that produces this result. In this case, if an answer exists, print the numbers of cyclical shifts that occurred during each of the n operations.

Input
The first line of the input contains an integer t (1≤t≤500) — the number of test cases in the test.

The descriptions of the test cases follow.

The first line of the description of each test case contains one integer n (2≤n≤2⋅103) — the length of the array a.

The next line contains the final state of the array a: n integers a1,a2,…,an (1≤ai≤n) are written. All ai are distinct.

It is guaranteed that the sum of n values over all test cases does not exceed 2⋅103.

Output
For each test case, print the answer on a separate line.

Print -1 if the given final value a cannot be obtained by performing an arbitrary number of cyclic shifts on each operation. Otherwise, print n non-negative integers d1,d2,…,dn (di≥0), where di means that during the i-th operation the first i elements of the array were cyclic shifted to the right di times.

If there are several possible answers, print the one where the total number of shifts is minimal (that is, the sum of di values is the smallest). If there are several such answers, print any of them.

Example
inputCopy
3
6
3 2 5 6 1 4
3
3 1 2
8
5 8 1 3 2 6 4 7
outputCopy
0 1 1 2 0 4 
0 0 1 
0 1 2 0 2 5 6 2 
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N = 1e5+1;	
 
int main () {
    FIO
    ll t;
	cin >> t;
	
	while (t--) {
		ll n;
		cin >> n;
		
		vector<ll> v(n);
		for (ll i = 0; i < n; i++) cin >> v[i];
		
		vector<ll> ans(n);
		for (ll i = n; i >= 1; i--) {
			auto it = find(v.begin(), v.end(), i);
			ans[i-1] = (it - v.begin() + 1)%i;
			rotate(v.begin(), it, v.end());
			v.erase(v.begin());
		}
		
		for (ll i = 0; i < n; i++) cout << ans[i] << " ";
		cout << "\n";
	}
}
