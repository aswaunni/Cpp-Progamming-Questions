/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans ie.
return all ri, cithan can flow to both oceans.


Example 1:
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

Example 2:
Input: heights = [[2,1],[1,2]]
Output: [[0,0],[0,1],[1,0],[1,1]]
*/

vector<int> dir= {-1, 0, 1, 0, -1};

void dfs(vector<vector<int>>& hts, vector<vector<bool>> &vis, int i, int j) {
    int n = hts.size(), m = hts[0].size();
    if (!vis[i][j]) {
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int r = i+ dir[k], c = j + dir[k+1];
            if (r >= 0 && c >= 0 && r < n && c < m && hts[r][c] >= hts[i][j]) {
                dfs(hts, vis, r, c);
            }
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& hts) {
    int n = hts.size(), m = hts[0].size();
    
    vector<vector<bool>> visP(n, vector<bool>(m, false));
    vector<vector<bool>> visA(n, vector<bool>(m, false));
    
    for (int j = 0; j < m; j++) {
        dfs(hts, visP, 0, j);
        dfs(hts, visA, n-1, j);
    }
    for (int i = 0; i < n; i++) {
        dfs(hts, visP, i, 0);
        dfs(hts, visA, i, m-1);
    }
    
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visP[i][j] && visA[i][j])
                ans.push_back({i, j});
        }
    }
    
    return ans;
}
