/*

Harshikaa and the Rain Problem Code: RAINDROPS
Add problem to Todo list
Submit (Practice)
There is a tree with N nodes numbered from 1 to N outside Harshikaa's house. The tree is rooted at node 1. Initially the tree was dry, there were no raindrops on any node of the tree. Suddenly it started raining, and every second a drop falls on all the leaf nodes of the tree. Also, every second any drop which wasn't already on the root node moves one node closer to the root.

Sometimes, strong winds shake the tree and all drops which were not on the root fall off. It is known that the wind will shake the tree M times at A1,A2,…AM seconds after it started raining.

If multiple events happen at the same second, they are in this order:

Raindrops move one node closer to the root.
New raindrops fall on the leaves.
Wind shakes the tree.
How many drops are there at the root right after the M-th shake?

Input Format
The first line of each input contains T - the number of test cases. The test cases then follow.
The first line of each test case contains two space-separated integers N and M - the number of nodes on the tree and the number of shake events.
N−1 lines follow, each line containing two space-separated integers U and V denoting an edge between node U and V on the tree.
The next line contains M space-separated integers A1,A2,…,AM - the timestamp of the shakes.
Output Format
For each test case, output in a single line the number of raindrops on the root right after the M-th shake.

Constraints
1≤T≤1000
2≤N≤100000
1≤U,V≤N
U≠V
1≤M≤100000
1≤Ai≤109
A is strictly increasing
Sum of N over all test cases is not more than 5⋅105
Sum of M over all test cases is not more than 4⋅105
Sample Input 1 
1
5 2
2 1
1 3
4 3
3 5
2 5
Sample Output 1 
5

//Explanation

We can see that each shake essentially resets the tree to the initial version. So, we can try to solve this problem for M independent time intervals and then add up the answer.

What we need now is an efficient method to calculate the answer for each interval. We know that a raindrop from a leaf which is at a distance of dd nodes from the root, will take d+1 seconds to reach the root. After a raindrop reaches the root for the first time, more raindrops will follow from that leaf and we will get a raindrop from that leaf indefinitely. Building upon this, let’s now take DD to be the distance of the leaf which is farthest from the root. Therefore after D seconds, we can be sure that the root is receiving X (the number of leaves) raindrops every second.

All we need to do now is to calculate how many raindrops the root receives for ≤D seconds after the tree is reset. To do so let’s define an array R such that Ri is the number of raindrops the root has after i seconds from a reset. We’ll also define an array L such that Li is the number of leaves at a distance of i from the root. R1 will be 0 because no drops can reach the root in the first second. Now, for all 1 < i ≤ D we can calculate Ri as R_{i-1} + sum(1, i-1) of Lj ie, the sum of raindrops that have already reached by i-1i−1 seconds and the number of new raindrops that will reach this second.

So, we will calculate our final answer by going over all M intervals. Let’s say Y is the duration of current interval, we will add RY to the answer if Y ≤ D, otherwise we will add RD + (X * (Y-D)) to the answer. X here is the number of total leaves in the tree.

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> nodes;
ll X = 0;
vector<int> L;
vector<int> dist;

void dfs(int node, int parent)
{
    for (auto& u : nodes[node]) {
        if (u != parent) {
            dist[u] = dist[node] + 1;
            dfs(u, node);
        }
    }
    
    if (nodes[node].size() == 1 && node != 0) {
        X++;
        L[dist[node]]++;
    }
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int n, m;
	    cin >> n >> m;
	    
	    X = 0;
	    nodes.clear(); L.clear(); dist.clear();
	    nodes.resize(n); L.resize(n); dist.resize(n);
	    
	    for (int i = 0; i < n-1; i++) {
	        int u, v;
	        cin >> u >> v;
	        --u; --v;
	        nodes[u].push_back(v);
	        nodes[v].push_back(u);
	    }
	    
	    vector<int> wind(m+1);
	    for (int i = 1; i <= m; i++)
	        cin >> wind[i];
	        
	    dfs(0, -1);
	    
	    ll D = n-1;
	    while (L[D] == 0)
	        --D;
	        
	    vector<ll> R(D+1);
	    ll lSum = 0;
	    for (int i = 1; i <= D; i++) {
	        R[i] = R[i-1] + lSum + L[i-1];
	        lSum += L[i-1];
	    }
	        
	    ll ans = 0;
	    for (int i = 1; i <= m; i++) {
	        ll interval = wind[i] - wind[i-1];
	        if (interval <= D)
	            ans += R[interval];
	        else
	            ans += R[D] + (interval - D) * X;
	    }
	    cout << ans << "\n";
	    
	}
	return 0;
}
