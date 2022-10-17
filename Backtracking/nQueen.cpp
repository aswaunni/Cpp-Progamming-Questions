/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
*/

void helper(int row, int n, vector<vector<string>>& ans, vector<string>& mtx, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2) {
    if (row == n) {
        ans.push_back(mtx);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (col[i] && diag1[row+i] && diag2[n-1+i-row]) {
            col[i] = diag1[row+i] = diag2[n-1+i-row] = false;
            mtx[row][i] = 'Q';
            helper(row+1, n, ans, mtx, col, diag1, diag2);
            col[i] = diag1[row+i] = diag2[n-1+i-row] = true;
            mtx[row][i] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> mtx(n, string(n, '.'));
    vector<bool> col(n, true);
    vector<bool> diag1(2*n-1, true);
    vector<bool> diag2(2*n-1, true);

    helper(0, n, ans, mtx, col, diag1, diag2);
    return ans;
}
