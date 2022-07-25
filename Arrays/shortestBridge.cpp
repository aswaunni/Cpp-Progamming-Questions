/*
ou are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1

//Hint : https://leetcode.com/problems/shortest-bridge/discuss/189293/C%2B%2B-BFS-Island-Expansion-%2B-UF-Bonus
*/

class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    queue<pair<int, int>> q;
    
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        
        if (i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 1) {
            grid[i][j] = 2;
            q.push({i, j});
        
            for (int d = 0; d < 4; d++)
                dfs(grid, i + dir[d], j + dir[d+1]);
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        
        for (int i = 0; i < n && q.empty(); i++) {
            for (int j = 0; j < n && q.empty(); j++) {
                dfs(grid, i, j);
            }
        }
        
        while (!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [i, j] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int x = i + dir[d], y = j + dir[d+1];
                    if (x >= 0 && y >= 0 && x < n && y < n) {
                        if (grid[x][y] == 1)
                            return grid[i][j] - 2;
                        if (grid[x][y] == 0) {
                            grid[x][y] = grid[i][j]+1;
                            q.push({x, y});   
                        }
                    }
                }
            }
        }
        return 0;
    }
};
