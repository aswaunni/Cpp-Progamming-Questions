/*
On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.


Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.

 

Example 1:

Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
Example 2:

Input: n = 1, k = 0, row = 0, column = 0
Output: 1.00000
*/

vector<vector<int>> dirs = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
double knightProbability(int n, int k, int row, int column) {
    return helper(n, k, row, column);
}

double helper(int n, int k, int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= n)
        return 0;

    if (k == 0)
        return 1;

    double ans = 0;
    for (auto& a : dirs) {
        int x = r + a[0], y = c + a[1];
        ans += 0.125 * helper(n, k-1, x, y);
    }
    return ans;
}

// OR

vector<vector<int>> dirs = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
vector<vector<vector<double>>> dp;

double knightProbability(int n, int k, int row, int column) {
    dp.resize(k+1, vector<vector<double>>(n, vector<double>(n, 0)));
    return helper(n, k, row, column);
}

double helper(int n, int k, int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= n)
        return 0;

    if (k == 0)
        return 1;

    if (dp[k][r][c] != 0)
        return dp[k][r][c];

    double ans = 0;
    for (auto& a : dirs) {
        int x = r + a[0], y = c + a[1];
        ans += 0.125 * helper(n, k-1, x, y);
    }
    return dp[k][r][c] = ans;
}
