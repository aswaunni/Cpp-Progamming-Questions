/*
A string S whose characters are one of the following 5: (, ), +, − and ?, is said to be a valid string if one of the following conditions holds:

S= ?
S=(x+y), where x and y are valid strings.
S=(x−y), where x and y are valid strings.
For example, strings ?, (?−?), (?+(?−?)) are valid strings, while strings (?−+), ??, (?), ?−?, (?+?)) are not.

The power of a valid string S is defined to be the maximum value attainable by replacing each ? in it by either 0 or 1 and evaluating the resulting expression.

For example, the power of (?−?) is 1 because we can obtain (1−0) which evaluates to 1.

You are given a valid string S, and Q queries on it. Each query is represented by two integers L and R (L≤R). Your task is to find the power of the substring SL,SL+1,…,SR. It is guaranteed that this substring is a valid string.

Note: The input of this problem is large, so use fast input/output methods.

Input Format
The first line of input contains an integer T, denoting the number of test cases. The description of T test cases follows:
The first line of each test case contains the string S.
The next line contains an integer Q, representing the number of queries to answer.
Each of the following Q lines contains two space-separated integers, L and R, representing the query.
Output Format
For each test case, print one line containing Q space-separated integers, the i-th of which represents the answer to the i-th query.

Constraints
1≤T≤1000
1≤|S|≤106
1≤Q≤106
1≤L≤R≤|S|
∑|S| and ∑Q over all test cases does not exceed 106.
Subtasks
Subtask #1 (20 points):

1≤|S|≤1000
1≤Q≤1000
∑|S| and ∑Q over all test case does not exceed 104.
Subtask #2 (80 points):

Original constraints
Sample Input 1 
3
(?+?)
2
2 2
1 5
(?-(?-?))
2
1 9
4 8
(?-(?+?))
1
1 9
Sample Output 1 
1 2
2 1
1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--) {
	    string s;
	    cin >> s;
	    int n = s.length();
	    
	    map<int, map<int, int>> m;
	    stack<int> operations;
	    stack<pair<int, int>> val;
	    
	    for (int i = 0; i < n; i++) {
	        if (s[i] == '?') {
	            m[i][i] = 1;
	            val.push({1, 0});
	        } else if (s[i] == ')') {
	            char op = s[operations.top()];
	            operations.pop();
	            int start = operations.top();
	            operations.pop();
	            
	            pair<int, int> x, y;
	            y = val.top();
	            val.pop();
	            x = val.top();
	            val.pop();
	            
	            int mn, mx;
	            if (op == '+') {
	                mx = x.first + y.first;
	                mn = x.second + y.second;
	            } else {
	                mx = x.first - y.second;
	                mn = x.second - y.first;
	            }
	            
	            val.push({mx, mn});
	            m[start][i] = mx;
	        } else {
	            operations.push(i);
	        }
	    }
	    
	    int q;
	    cin >> q;
	    
	    while (q--) {
	        int a, b;
	        cin >> a >> b;
	        cout << m[a-1][b-1] << " ";
	    }
	    cout << "\n";
	}
	return 0;
}
