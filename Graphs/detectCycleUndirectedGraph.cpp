#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+2;

bool isCycle(int i, vector<vector<int>> adjList, vector<bool> &vis, int parent) {
    vis[i] = true;
    for (auto& a : adjList[i]) {
        if (a != parent) {
            if (vis[a])
                return true;
            if (!vis[a] && isCycle(a, adjList, vis, i))
                return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adjList(n);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    
    bool cycle = false;
    vector<bool> vis(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!vis[i] && isCycle(i, adjList, vis, -1))
            cycle = true;
    }
    cout << cycle;
    
    return 0;
}
