/*
You are given a positive integer X which is at most 108.

Find three distinct non-negative integers A,B,C that do not exceed 109 and satisfy the following equation:

(A∣B)&(B∣C)&(C∣A)=X
Here, ∣ denotes the bitwise OR operator and & denotes the bitwise AND operator.

It can be shown that a solution always exists for inputs satisfying the given constraints. If there are multiple solutions, you may print any of them.

Input Format
The first line contains an integer T, the number of test cases. The description of T test cases follows.
Each test case consists of a single line containing one integer, X.
Output Format
For each test case, print on a new line three different space-separated integers A,B,C.
Your output will be considered correct only if A,B,C are distinct non-negative integers not exceeding 109 that satisfy the equation given in the problem statement.
If there are multiple solutions, you may print any of them.
Constraints
1≤T≤100
1≤X≤108
0≤A,B,C≤109
A,B,C must be pairwise distinct
Sample Input 1 
4
3
2
13
100000000
Sample Output 1 
1 2 3
2 3 4
6 9 13
23570468 129811858 80835401
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int x;
	    cin >> x;
	    
	    int a = x, b = x, c = 0;
	    for (int i = 0; i < 31; i++) {
	        if (!(b&(1<<i))) {
	            b |= (1<<i);
	            break;
	        }
	    }
	    cout << a << " " << b << " " << c << "\n";
	}
	return 0;
}
