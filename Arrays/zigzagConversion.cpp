/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
*/

string convert(string s, int n) {
    
    if(n==1)
        return s;
    
    string ans;
    bool goingDown = false;
    vector<string> v(min(n, (int)s.length()));
    int curRow = 0;
    
    for (auto& c : s) {
        v[curRow] += c;
        if (curRow == 0 || curRow == n-1)
            goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }
    
    for (string row : v)
        ans += row;
    return ans;
}
