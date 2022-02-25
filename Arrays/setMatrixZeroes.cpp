/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

*/

void setZeroes(vector<vector<int>>& mx) {
    bool colFirst = false;
    int n = mx.size(), m = mx[0].size();
    
    for (int i = 0; i < n; i++) {
        if (mx[i][0] == 0)
            colFirst = true;
        
        for (int j = 1; j < m; j++) {
            if (mx[i][j] == 0) {
                mx[0][j] = 0;
                mx[i][0] = 0;
            }
        }
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mx[i][0] == 0 || mx[0][j] == 0)
                mx[i][j] = 0;
        }
    }
    
    if (mx[0][0] == 0) {
        for (int j = 0; j < m; j++)
            mx[0][j] = 0;
    }
    
    if (colFirst) {
        for (int i = 0; i < n; i++)
            mx[i][0] = 0;
    }
}

// OR

    void setZeroes(vector<vector<int>>& mx) {
    int n = mx.size(), m = mx[0].size();
    set<int> r,c;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mx[i][j] == 0) {
                r.insert(i);
                c.insert(j);
            }
        }
    }
    
    for (auto& a: r) {
        for (int j = 0; j < m; j++)
            mx[a][j] = 0;
    }
    
    for (auto& a : c) {
        for (int i = 0; i < n; i++)
            mx[i][a] = 0;
    }
}
