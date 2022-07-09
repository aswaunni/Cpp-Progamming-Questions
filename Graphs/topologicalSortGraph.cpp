/*
Topological ordering is ordering of nodes in a directed graph where for each directed edge from node A to node B, node A appears before node B.
Its not unique ordering.
Only DAG(directed Acyclic Graphs can be sorted topologically.

eg.
      1 - 7
     / \
    1   2
   / \   \
  3   4   5
 ans - D E F G B C A
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adjList(n);
    vector<int> inDegree(n, 0);

    int x, y;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        adjList[x-1].push_back(y-1);
        inDegree[y-1]++;
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }
    
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        cout << f+1 << " ";
        
        for (auto& a : adjList[f]) {
            inDegree[a]--;
            if (inDegree[a] == 0)
                q.push(a);
        }
    }
    return 0;
}



