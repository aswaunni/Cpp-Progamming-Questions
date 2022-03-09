/*
Chef has 2 strings A and B of equal length N. Both strings contain lowercase english alphabets only.

Chef can perform several moves on string A. In one move, Chef has to:

Select an index i (1≤i≤N−1).
Replace A[i] with (A[i]+1).
Replace A[i+1] with (A[i+1]+1).
For example, if A=abcze, a valid move would be to select index 3. This way the string becomes abdae after performing the move. Note that the value at an index is cyclically incremented. This means that, a→b, b→c, …, z→a.

Chef has been asked to answer Q queries. Each query is of the form:

L R: Given 1≤L≤R≤N, Chef wants to know if it is possible to convert the substring A[L,R] to B[L,R] by performing the above mentioned move any number of times.
For each query, output in a single line Yes, if the conversion is possible using any number of moves. Otherwise, print No.

NOTE: Queries are independent. Thus, the original strings A and B would be retained to process next query. For each query solve for substrings A[L,R] and B[L,R] only. So valid values for i will be among L to R−1 only.

Input Format
The first line will contain T - the number of test cases. Then the test cases follow.
First line of each test case contains two integers N,Q.
Second line of each test case contains string A.
Third line of each test case contains string B.
Q lines follow, where the ith line contains two integers LiRi - the ith query.
Output Format
Output Q lines, where the ith line contains the answer to the ith query. The answer is Yes, if the conversion is possible using any number of moves. Otherwise, the answer is No.

You may print each character of the string in uppercase or lowercase (for example, the strings yEs, yes, Yes and YES will all be treated as identical).

Constraints
1≤T≤1000
2≤N≤105
1≤Q≤2⋅105
1≤L≤R≤N
Sum of N over all test cases does not exceed 2⋅105.
Sum of Q over all test cases does not exceed 2⋅105.
Sample Input 1 
1
5 3
abcdz
nbhea
2 2
1 3
4 5
Sample Output 1 
Yes
No
Yes
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
	ll t;
	cin >> t;
	
	while (t--) {
	    ll n, q;
	    cin >> n >> q;
	    string a, b;
	    cin >> a >> b;
	    vector<ll> v(n), o(n), e(n);
	    for (ll i = 0; i < n; i++) {
	        if (b[i] >= a[i])   v[i] = (b[i] - a[i]); 
            else                v[i] = 26 - (a[i] - b[i]);  
	    }
	    
	    e[0] = v[0];
	    o[0] = 0;
	    for (ll i = 1; i < n; i++) {
	        if (i%2 == 0) {
	            e[i] = e[i-1] + v[i];
	            o[i] = o[i-1];
	        } else {
	            o[i] = o[i-1] + v[i];
	            e[i] = e[i-1];
	        }
	    }
	    for (ll i = 0; i < q; i++) {
	        ll sum_e = 0, sum_o = 0;
	        ll x, y;
	        cin >> x >> y;
	        if (x > 1) {
	            sum_e -= e[x-2];
	            sum_o -= o[x-2];
	        }
	        
	        sum_e += e[y-1];
	        sum_o += o[y-1];
	        
	        cout << (abs(sum_e-sum_o) % 26 == 0 ? "YES\n": "NO\n");
	    }
	}
	return 0;
}
