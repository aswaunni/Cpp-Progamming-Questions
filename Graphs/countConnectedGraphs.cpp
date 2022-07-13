#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adjList[N];

int dfs(int r) {
    vis[r] = true;
    int x = 1;
    
    for (auto& a : adjList[r]) {
        if (!vis[a]) {
            x += dfs(a);
        }
    }
    return x;
}

int main()
{
    for (int i = 0; i < N; i++) vis[i] = false;
    
    int n, m;
    cin >> n >> m;
    
    int x, y;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    
    vector<int> sz;
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            sz.push_back(dfs(i));
    }
    
    cout << sz.size() << endl;
    for (auto& a : sz)
        cout << a << " ";
    return 0;
}
