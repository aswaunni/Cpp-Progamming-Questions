/*
You are given an array A consisting of N integers.

From array A, we create a new array B containing all pairwise bitwise ANDs of elements from A. That is, B consists of N⋅(N−1)/2 elements, each of the form Ai&Aj for some 1≤i<j≤N.

In array B, we repeat the following process till there is only one element remaining:

Let the current maximum and minimum element of array B be X and Y respectively.
Remove X and Y from array B and insert X|Y into it.
Determine the last remaining element in array B.

Here, & denotes the Bitwise AND operation and | denotes the Bitwise OR operation.

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N, denoting the number of elements in A.
The second line of each test case contains N space-separated integers A1,A2,…,AN.
Output Format
For each test case, print a single line containing one integer — the last remaining element in array B.

Constraints
1≤T≤104
2≤N≤105
0≤Ai≤109
The sum of N over all test cases does not exceed 2⋅105.
Sample Input 1 
3
2
1 3
3
2 7 1
4
4 6 7 2
Sample Output 1 
1
3
6

****HINT***
ORs result in set bit if any of the bits are set and for AND more than 1 bit should be set.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    
	    vector<int> v(n);
	    for(int i = 0; i < n; i++) 
	        cin >> v[i];

        int ans = 0;
	    for (int i = 0; i < 32; i++) {
	        int count = 0;
	        for (int j = 0; j < n; j++) {
	            if (v[j]&1)
	                count++;
	            v[j] >>= 1;
	        }
	        if (count > 1)
	            ans += pow(2, i);
	            
	    }
	    cout << ans << "\n";
	    
	}
	return 0;
}
