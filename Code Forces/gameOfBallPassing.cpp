/*
Daniel is watching a football team playing a game during their training session. They want to improve their passing skills during that session.

The game involves n players, making multiple passes towards each other. Unfortunately, since the balls were moving too fast, after the session Daniel is unable to know how many balls were involved during the game. The only thing he knows is the number of passes delivered by each player during all the session.

Find the minimum possible amount of balls that were involved in the game.

Input
There are several test cases in the input data. The first line contains a single integer t (1≤t≤5⋅104) — the number of test cases. This is followed by the test cases description.

The first line of each test case contains one integer n (2≤n≤105) — the number of players.

The second line of the test case contains a sequence of integers a1,a2,…,an (0≤ai≤109), where ai is the number of passes delivered by the i-th player.

It is guaranteed that the sum of n over all test cases doesn't exceed 105.

Output
For each test case print a single integer — the answer to the problem.

Example
inputCopy
4
4
2 3 3 2
3
1 5 2
2
0 0
4
1000000000 1000000000 1000000000 1000000000
outputCopy
1
2
0
1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
 
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll t;
  cin >> t;
  
  while (t--) {
	ll n;
	cin >> n;
	
	ll mx = 0, s = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		mx = max(x, mx);
		s += x;
	}
	
	s -= mx; // sum of rest of elements
	
	if (mx == 0)
		cout << "0\n";
	else if (s >= mx)
		cout << "1\n";
	else
		cout << mx - s << "\n";
  }
}
