/*
Chef recently created a new Tiling Window Manager called ChefWM. He wants to find out the maximum number of columns of windows he can fit on the screen and he needs your help.

Consider the screen to be an axis-aligned rectangle in the xy-plane, with its bottom-left corner at (0,0) and top-right corner at (N,M) (that is, the screen has width N units and height M units). ChefWM works as follows:

First, the screen is divided into one or more columns of equal integer width.
Then, each column is divided into two or more windows of equal integer height. Note that all windows within a column must have the same height, but windows in different columns may have different heights.
Finally, Chef would like the following condition to hold:
No two windows from different columns can have their horizontal boundary share the same y-coordinate (apart from y=0 and y=M). See the figures below for more details.
It is not allowed to leave any empty space on the screen, i.e, the division performed in the first two steps above must cover the entire screen.

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
Each test case consists of a single line of input, containing two space-separated integers N,M — the coordinates of the top-right corner of the screen.
Output Format
For each test case, output a single line containing one integer — the maximum number of columns ChefWM can create for the screen.

Constraints
1≤T≤500
1≤N≤109
1≤M≤109
Sample Input 1 
5
8 210
1 100
100 5
10 1
9 2310
Sample Output 1 
4
1
1
0
3
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
	    int n, m;
	    cin >> n >> m;
	    
	    int cnt = 0;
	    int temp = m;
	    for (int i = 2; i*i <= m; i++) {
	        if (temp%i == 0) {
	            cnt++;
	            while (temp%i == 0)
	                temp /= i;
	        }
	    }
	    
	    if (temp > 1)
	        cnt++;
	        
	   set<int> s;
	   for(int i = 1; i*i <= n; i++) {
	       if (n%i == 0) {
	           s.insert(i);
	           if (i != n/i)
	               s.insert(n/i);
	       }
	   }
	   
	   int ans = 0;
	   for (auto& a : s) {
	       if (a <= cnt)
	           ans = a;
	   }
	   cout << ans << "\n";
	}
	return 0;
}
