/*
There is an array A with N elements. Each element of A has a fixed polarity: either north or south.

Chef is allowed to perform some (possibly zero) operations on the array A. In one operation, Chef can:

Pick some subarray of array A, such that, the first and last elements of the subarray have different polarities, and, rearrange the elements in this subarray any way he wants.
Note that the polarity of each element remains unchanged after an operation.

Find the minimum number of operations required to sort the array in non-decreasing order, or state that it is impossible.

A subarray of A is obtained by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

Input Format
The first line contains an integer T, denoting the number of test cases. The T test cases then follow.
The first line of each test case contains a single integer N.
The second line of each test case contains N space-separated integers A1,A2,…,AN.
The third line of each test case contains a string of length N, the ith character of which is either N or S, representing that the ith element of A has north or south polarity, respectively.
Output Format
For each test case, if it impossible to sort the array, output −1. Otherwise, output a single integer: the minimum number of operations required to sort the array.

Constraints
1≤T≤105
1≤N≤2⋅105
1≤Ai≤109
The sum of N across all test cases doesn't exceed 2⋅105.
Subtasks
Subtask #1 (100 points): original constraints

Sample Input 1 
6
5
1 3 2 3 7
NNSNS
2
2 1
SS
3
1 8 12
SNS
3
3 2 1
NSN
5
1 2 3 5 4
NSNSN
5
1 1 2 2 1
SNSNN
Sample Output 1 
1
-1
0
2
1
1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    vector<int> v(n);
	    for (int i = 0; i < n; i++)
	        cin >> v[i];
	    string s;
	    cin >> s;

	    if(is_sorted(v.begin(), v.end()))
        {
          cout << "0" << endl;
          continue;
        }
        
        int ct=0;
        for(auto x:s)
        {
            if(x=='N')
            ct++;
        }
        
        if(ct == n || ct == 0)
        {
           cout << "-1" << endl;
           continue;
        }
         
	    vector<int> b(v);
	    sort(b.begin(), b.end());
	    
	    int start = INT_MAX, end = INT_MIN;
	    for (int i = 0; i < n; i++) {
	        if (v[i] != b[i]) {
	            start = min(start, i);
	            end = max(end, i);
	        }
	    }
	    
	    bool f1 = false, f2 = false;
	    for (int i = 0; i < start; i++)
	        if (s[i] != s[end])
	            f1 = true;
	            
	    for (int i = end; i < n; i++)
	        if (s[i] != s[start])
	            f1 = true;
	            
	    if (s[start] != s[end] || f1 || f2)
	        cout << "1" << endl;
	    else
	        cout << "2" << endl;
	}
	return 0;
}
