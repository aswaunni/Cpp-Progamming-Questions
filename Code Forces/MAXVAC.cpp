/*
You are given Chef's calendar for the next N days, defined as a binary string S of length N where Si=0 means that Chef has a holiday on the ith day from now, and Si=1 means that Chef has to work on that day.

Chef wants to plan his vacations. For each vacation, Chef needs X consecutive holidays in his calendar. Obviously, he can only go on one vacation at a time.

Chef can take at most one extra holiday. That is, he can flip at most one digit in S from 1 to 0. If he does this optimally, what is the maximum number of vacations that he can go on?

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and X.
The second line of each test case contains a binary string S of length N — Chef's schedule.
Output Format
For each test case, output on a new line the answer — the maximum number of vacations Chef can take if he takes at most one more extra holiday.

Constraints
1≤T≤1000
1≤N≤2⋅105
1≤X≤N
The sum of N across all test cases does not exceed 2⋅105
Sample Input 1 
3
7 2
0010001
4 3
1010
5 2
00100
Sample Output 1 
3
1
2
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int n, x;
	    cin >> n >> x;
	    
	    string s;
	    cin >> s;
	    
	    vector<int> v;
	    int c = 0, sum = 0;
	    for (int i = 0; i <= n; i++) {
	        if (i < n && s[i] == '0')
	            c++;
	        else if (i > 0) {
	            v.push_back(c);
	            sum += c/x;
	            c = 0;
	        }
	    }
	    
	    int ans = 0;
	    for (int i = 1; i < v.size(); i++) {
	        int temp = sum - v[i-1]/x - v[i]/x;
	        ans = max(ans, temp + (v[i] + v[i-1] + 1)/x);
	    }
	    cout << ans << "\n";
	}
	return 0;
}
