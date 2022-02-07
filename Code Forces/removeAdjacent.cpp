/*
Remove Adjacent Problem Code: REMADJ

You are given an array A of length N.

You can perform the following operation on the array, as long as it has more than one element:

Choose any two adjacent elements, remove them from the array and insert their sum at that position.
Formally, if the current length of the array is |A|, you can choose an index 1≤i<|A|, and transform the array into [A1,A2,…,Ai−1,Ai+Ai+1,Ai+2,…,AN].
Note that after each operation, the length of array decreases by exactly 1.

Print the minimum number of operations to be applied on array A such that all the elements in the resulting array are equal. See sample explanation for more details.

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
Each test case consists of two lines of input.
The first line contains an integer N.
The second line contains N space-separated integers, the elements of array A.
Output Format
For each test case, output on a new line the minimum number of operations required to make all the elements equal.

Sample Input 1 
4
3
5 2 3
2
6 9
5
3 6 5 4 9
3
3 3 3
Sample Output 1 
1
1
2
0
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    
	    vector<int> v(n+1, 0);
	    vector<int> s(n+1, 0);
	    
	    for (int i = 1; i <= n; i++) {
	        cin >> v[i];
	        s[i] = s[i-1] + v[i];
	    }
	    
	    int ans, sum = s[n];
	    for (int i = n; i > 0; i--) {
	        if (sum%i != 0)
	            continue;
	        
	        int count = 1;
	        for (int j = 1; j <= n; j++) {
	            if (s[j] == count*(sum/i))
	                count++;
	        }
	        
	        if (count-1 >= i) {
	            ans = n-i;
	            break;
	        }
	    }
	    cout << ans << "\n";
	}
	return 0;
}
