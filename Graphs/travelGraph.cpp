/*
You are given a graph with N vertices (numbered 1 to N) and M bidirectional edges, which doesn't contain multiple edges or self-loops — that is, the given graph is a simple undirected graph.

For each pair of vertices a,b such that 1≤a,b≤N, it is possible to add a new edge between vertices a and b to the graph, with a cost of (a−b)2.

Find the minimum cost of adding edges so that vertex N is reachable from vertex 1.

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains 2 space-separated integers, N and M.
The ith of the next M lines contains 2 space-separated integers ui and vi, denoting a bidirectional edge between vertex ui and vertex vi in the graph.
Output Format
For each test case, output the answer in a single line.

Constraints
1≤T≤1000
2≤N≤2⋅105
0≤M≤2⋅105
1≤ui,vi≤N
The graph doesn't contain self-loops or multiple edges
Sum of N over all testcases is no more than 2⋅105.
Sum of M over all testcases is no more than 2⋅105.
Sample Input 1 
3
2 0
5 4
3 2
1 4
5 3
4 2
6 3
1 2
3 2
1 3
Sample Output 1 
1
0
3
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int i, vector<bool> &vis, queue<int> &q)
{
    vis[i] = true;
    q.push(i);
    for (auto &u : adj[i])
    {
        if (!vis[u])
            dfs(adj, u, vis, q);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a, b;
        vector<int> adj[n + 1];
        vector<bool> vis(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int cnt = 0;
        queue<int> q;
        bool flag = 0;
        dfs(adj, 1, vis, q);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int node = q.front();
                q.pop();
                if (node == n)
                {
                    flag = 1;
                    break;
                }
                if (node - 1 >= 1 and !vis[node - 1])
                    dfs(adj, node - 1, vis, q);
                if (node + 1 <= n and !vis[node + 1])
                    dfs(adj, node + 1, vis, q);
            }
            if (flag == 1)
                break;
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
