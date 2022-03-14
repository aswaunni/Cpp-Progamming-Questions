/*
You are given n distinct points on a plane. The coordinates of the i-th point are (xi,yi).

For each point i, find the nearest (in terms of Manhattan distance) point with integer coordinates that is not among the given n points. If there are multiple such points — you can choose any of them.

The Manhattan distance between two points (x1,y1) and (x2,y2) is |x1−x2|+|y1−y2|.

Input
The first line of the input contains one integer n (1≤n≤2⋅105) — the number of points in the set.

The next n lines describe points. The i-th of them contains two integers xi and yi (1≤xi,yi≤2⋅105) — coordinates of the i-th point.

It is guaranteed that all points in the input are distinct.

Output
Print n lines. In the i-th line, print the point with integer coordinates that is not among the given n points and is the nearest (in terms of Manhattan distance) to the i-th point from the input.

Output coordinates should be in range [−106;106]. It can be shown that any optimal answer meets these constraints.

If there are several answers, you can print any of them.

Examples
inputCopy
6
2 2
1 2
2 1
3 2
2 3
5 5
outputCopy
1 1
1 1
2 0
3 1
2 4
5 4
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N = 2e5+5;	
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

map <pair<ll, ll>, ll> m;
queue <ll> q;
ll x[N], y[N], vis[N], ansx[N], ansy[N];
ll n;
 
void solve() {
    cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		m[make_pair(x[i], y[i])] = i;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			ll x_ = x[i]+dx[j], y_ = y[i]+dy[j];
			if(!m.count(make_pair(x_, y_))) {
				vis[i] = 1;
				ansx[i] = x_;
				ansy[i] = y_;
				q.push(i);
				break;
			}
		}
	}
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		for (int j = 0; j < 4; j++) {
			ll x_ = x[u]+dx[j], y_ = y[u]+dy[j];
			if(m.count(make_pair(x_, y_))) {
				ll v = m[make_pair(x_, y_)];
				if (!vis[v]) {
					ansx[v] = ansx[u];
					ansy[v] = ansy[u];
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++)
		cout << ansx[i] << " " << ansy[i] << "\n";
}

int main () {
    FIO
    solve();
}
