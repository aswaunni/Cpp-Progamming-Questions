#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adjList[N];

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
    
    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty()) {
        int f = q.front();
        q.pop();
        
        cout << f << " ";
        for (auto& a : adjList[f]) {
            if (!vis[a]) {
                q.push(a);
                vis[a] = true;
            }
        }
    }
    return 0;
}
