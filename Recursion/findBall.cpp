/*
You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.

A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.

Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.

Example 1:
Input: grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
Output: [1,-1,-1,-1,-1]

Example 2:
Input: grid = [[-1]]
Output: [-1]

Example 3:
Input: grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
Output: [0,1,2,3,4,-1]
 

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] is 1 or -1.
*/

int DFS(vector<vector<int>> &v, int i, int j, int m, int n) {
    if (j >= n || j < 0)
        return -1;
        
    if (i == m)
        return j;
        
    if (v[i][j] == 1) {
        if ((j+1) < n && v[i][j+1] == 1)
            return DFS(v, i+1, j+1, m, n);
    } else {
        if ((j-1) >= 0 && v[i][j-1] == -1)
            return DFS(v, i+1, j-1, m, n);
    }
    return -1;
}
vector<int> findBall(vector<vector<int>>& v) {
    vector<int> ans;
    for(int j = 0; j < v[0].size(); j++)
        ans.push_back(DFS(v, 0, j, v.size(), v[0].size()));
    return ans;
}
