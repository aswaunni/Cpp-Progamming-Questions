/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
*/

int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> h(m+1, 0);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        stack<int> s;
        for (int j = 0; j <= m; j++) {
            if (j < m) {
                if (matrix[i][j] == '1')
                    h[j] += 1;
                else
                    h[j] = 0;
            }

            while (!s.empty() && h[j] <= h[s.top()]) {
                int ht = h[s.top()];
                s.pop();
                ans = max(ans, ht * (s.empty() ? j : j - s.top() - 1));
            }
            s.push(j);
        }
    }
    return ans;
}
