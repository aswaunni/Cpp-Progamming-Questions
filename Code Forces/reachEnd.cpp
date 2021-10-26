/*
You are given a positive integer N. Consider a square grid of size N×N, with rows numbered 1 to N from top to bottom and columns numbered 1 to N from left to right. Initially you are at (1,1) and you have to reach (N,N). From a cell you can either move one cell to the right or one cell down (if possible). Formally, if you are at (i,j), then you can either move to (i+1,j) if i<N, or to (i,j+1) if j<N.

There are exactly N blocks in the grid, such that each row contains exactly one block and each column contains exactly one block. You can't move to a cell which contains a block. It is guaranteed that blocks will not placed in (1,1) and (N,N).

You have to find out whether you can reach (N,N).

Input Format
The first line contains T - the number of test cases. Then the test cases follow.
The first line of each test case contains N - the size of the square grid.
The i-th line of the next N lines contains two integers Xi and Yi indicating that (Xi,Yi) is the position of a block in the grid.
Output Format
For each test case, if there exists a path from (1,1) to (N,N), output YES, otherwise output NO.

You may print each character of the string in uppercase or lowercase (for example, the strings yEs, yes, Yes and YES will all be treated as identical).

Constraints
1≤T≤1000
2≤N≤106
1≤Xi,Yi≤N
(Xi,Yi)≠(1,1) and (Xi,Yi)≠(N,N) for all 1≤i≤N
Xi≠Xj and Yi≠Yj for all 1≤i<j≤N
Sum of N over all test cases does not exceed 106
Sample Input 1 
2
3
1 2
2 3
3 1
2
1 2
2 1
Sample Output 1 
YES
NO
*/

#include <bits/stdc++.h>
using namespace std;

struct cell {
    int x;
    int y;
};

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    
	    vector<cell> v(n);
	    
	    for (int i = 0; i < n; i++)
	        cin >> v[i].x >> v[i].y;
	    
	    sort(v.begin(), v.end(), [](cell a, cell b) {
	        return (a.x < b.x);
	    });
	    
	    int topleft = -1, rightbottom = -1;
	    
	    for (int i = 1; i < n; i++) {
	        if(v[i].y == v[i-1].y-1)
	            topleft = i;
	        else
	            break;
	    }
	    
	    for (int i = n-2; i >= 0; i--) {
	        if(v[i].y == v[i+1].y+1)
	            rightbottom = i;
	        else
	            break;
	    }
	    
	    if (v[topleft].y == 1 || v[rightbottom].y == n)
	        cout << "NO\n";
	    else
	        cout << "YES\n";
	    
	}
	
	
	return 0;
}
