/*
Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.
*/

class NumMatrix {
public:
    
    vector<vector<int>> v;
    NumMatrix(vector<vector<int>>& mtx) {
        int n = mtx.size(), m = mtx[0].size();
        v = vector<vector<int>>(n+1, vector<int>(m+1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j)
                v[i][j] = mtx[i-1][j-1] + v[i-1][j] + v[i][j-1] - v[i-1][j-1];        
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return v[r2+1][c2+1] - v[r2+1][c1] - v[r1][c2+1] + v[r1][c1];
    }
};
