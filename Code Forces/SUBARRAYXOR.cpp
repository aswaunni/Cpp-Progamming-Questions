/*
JJ is back with another challenge. He challenges you to construct an array A containing N integers such that the following conditions hold:

For all 1≤i≤N, 1≤Ai≤106
Every subarray has non-zero XOR. That is, for every 1≤L≤R≤N, AL⊕AL+1⊕…⊕AR≠0. Here, ⊕ denotes the bitwise XOR operation.
Can you complete JJ's challenge?

Under the given constraints, it can be proved that there always exists at least one array satisfying these conditions. If there are multiple possible arrays, print any of them.

Input Format
The first line contains a single integer T, denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains an integer N — the size of the array A to be constructed.
Output Format
For each test case, output a single line containing N space-separated integers, denoting the elements of array A. The ith of these N integers is Ai. If multiple arrays exist which satisfy the conditions, print any of them.

Constraints
1≤T≤1000
1≤N≤105
It is guaranteed that the sum of N over all test cases does not exceed 2⋅105.
Sample Input 1 
3
1
6
6
Sample Output 1 
7
1 2 4 8 16 32
2 3 5 7 11 13
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    
	    cout << "1 ";
	    for (int i = 2; i <= n; i++)
	        cout << (i ^ (i-1)) << " ";

	    cout << "\n";
	}
	return 0;
}
