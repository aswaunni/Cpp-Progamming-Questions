/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
*/

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    queue<pair<int, int>> q;
    vector<int> dir = {0, 1, 0, -1, 0};
    int n= mat.size(), m = mat[0].size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0)
                q.push({i, j});
            else
                mat[i][j] = -1;
        }
    }
    
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int R = r + dir[i], C = c + dir[i+1];
            if (R < 0 || C < 0 || R == n || C == m || mat[R][C] != -1)
                continue;
            
            mat[R][C] = mat[r][c] + 1;
            q.push({R, C});
        }
    }
    return mat;
}
