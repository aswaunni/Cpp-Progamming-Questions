#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adjList[N];

void dfs(int r) {
    vis[r] = true;
    cout << r << " ";
    
    for (auto& a : adjList[r]) {
        if (!vis[a]) {
            dfs(a);
        }
    }
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
    
    dfs(1);
    return 0;
}
