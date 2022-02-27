/*
Given a grid of size n*m (n is number of rows and m is number of columns grid has) consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
 

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands one is colored in blue 
and other in orange.
*/

void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
    int n = grid.size(), m = grid[0].size();
    
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0' || visited[i][j])
        return;
    
    visited[i][j] = true;
    dfs(grid, i+1, j, visited);
    dfs(grid, i, j+1, visited);
    dfs(grid, i+1, j+1, visited);
    dfs(grid, i-1, j, visited);
    dfs(grid, i, j-1, visited);
    dfs(grid, i-1, j-1, visited);
    dfs(grid, i+1, j-1, visited);
    dfs(grid, i-1, j+1, visited);
    

// Function to find the number of islands.
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == '1') {
                dfs(grid, i, j, visited);
                ans++;
            }
        }   
    }
    return ans;
}
