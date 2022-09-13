/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
Example 2:

Input: board = [["X"]]
Output: [["X"]]
*/

void solve(vector<vector<char>>& board) {
    int n = board.size(), m = board[0].size();
    
    if (n == 0 || m == 0 || n < 2 || m < 2)
        return;
    
    for (int i = 0; i < n; i++) {
        check(board, i, 0, n, m);
        check(board, i, m-1, n, m);
    }
    for (int j = 0; j < m; j++) {
        check(board, 0, j, n, m);
        check(board, n-1, j, n, m);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == '*')
                board[i][j] = 'O';
        }
    }
}

void check(vector<vector<char>>& board, int i, int j, int n, int m) {
    if (i >= n || i < 0 || j < 0 || j >= m || board[i][j] != 'O')
        return;
    
    board[i][j] = '*';
    
    check(board, i+1, j, n, m);
    check(board, i-1, j, n, m);
    check(board, i, j+1, n, m);
    check(board, i, j-1, n, m);
}
