/*
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

 

Example 1:


Input: grid = [" /","/ "]
Output: 2
Example 2:


Input: grid = [" /","  "]
Output: 1
Example 3:


Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
*/

// Hint: Split each cell

void dfs(vector<vector<int>>& v, int i, int j, int n) {
    if (i < 0 || j < 0 || i >= n*3 || j >= n*3 || v[i][j])
        return;
    
    v[i][j] = 1;
    
    dfs(v, i+1, j, n);
    dfs(v, i-1, j, n);
    dfs(v, i, j+1, n);
    dfs(v, i, j-1, n);
}

int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();
    
    vector<vector<int>> v(n*3, vector<int>(n*3, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '/')
                v[i*3][j*3+2] = v[i*3+1][j*3+1] = v[i*3+2][j*3] = 1;    
            else if (grid[i][j] == '\\')
                v[i*3][j*3] = v[i*3+1][j*3+1] = v[i*3+2][j*3+2] = 1;
        }
    }
    
    int count = 0;
    for (int i = 0; i < n*3; i++) {
        for (int j = 0; j < n*3; j++) {
            if (!v[i][j]) {
                count++;
                dfs(v, i, j, n);
            }
        }
    }
    return count;
}
