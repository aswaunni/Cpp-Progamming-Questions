/*
Egor has a table of size n×m, with lines numbered from 1 to n and columns numbered from 1 to m. Each cell has a color that can be presented as an integer from 1 to 105.

Let us denote the cell that lies in the intersection of the r-th row and the c-th column as (r,c). We define the manhattan distance between two cells (r1,c1) and (r2,c2) as the length of a shortest path between them where each consecutive cells in the path must have a common side. The path can go through cells of any color. For example, in the table 3×4 the manhattan distance between (1,2) and (3,3) is 3, one of the shortest paths is the following: (1,2)→(2,2)→(2,3)→(3,3).

Egor decided to calculate the sum of manhattan distances between each pair of cells of the same color. Help him to calculate this sum.

Input
The first line contains two integers n and m (1≤n≤m, n⋅m≤100000) — number of rows and columns in the table.

Each of next n lines describes a row of the table. The i-th line contains m integers ci1,ci2,…,cim (1≤cij≤100000) — colors of cells in the i-th row.

Output
Print one integer — the the sum of manhattan distances between each pair of cells of the same color.

Examples
inputCopy
2 3
1 2 3
3 2 1
outputCopy
7
inputCopy
3 4
1 1 2 2
2 1 1 2
2 2 1 1
outputCopy
76
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const ll N = 1e5+1;	
vector<ll> x[N];
vector<ll> y[N];
 
int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll r, c;
	cin >> r >> c;

	for (ll i = 0; i < r; i++) {
		for (ll j = 0; j < c; j++) {
			ll a;
			cin >> a;
			x[a].push_back(i);
			y[a].push_back(j);
		}
	}
	
	ll ans = 0;
	
	for (ll k = 1; k <= N; k++) {
	    sort(x[k].begin(), x[k].end());
	    sort(y[k].begin(), y[k].end());
	    ll sum_x = 0, sum_y = 0;
		for (ll j = 0; j < x[k].size(); j++) {
			ans += (j*x[k][j] - sum_x);
			ans += (j*y[k][j] - sum_y);
			sum_x += x[k][j];
			sum_y += y[k][j];
		}
	}
	cout << ans << "\n";
}
