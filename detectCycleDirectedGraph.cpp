#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+2;

bool isCycle(int i, vector<vector<int>> adjList, vector<bool> &vis, vector<bool>& stack) {
    stack[i] = true;
    vis[i] = true;
    for (auto& a : adjList[i]) {
        if (!vis[a] && isCycle(a, adjList, vis, stack))
            return true;
        if (stack[a])
            return true;
    }
    stack[i] = false;
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
    }
    
    bool cycle = false;
    vector<bool> vis(n, false);
    vector<bool> stack(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!vis[i] && isCycle(i, adjList, vis, stack))
            cycle = true;
    }
    cout << cycle;
    
    return 0;
}
