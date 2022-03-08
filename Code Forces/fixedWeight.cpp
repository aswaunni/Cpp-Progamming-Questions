/*
A permutation of length N is an array of N integers (P1,P2,…,PN) where every integer from 1 to N (inclusive) appears in it exactly once. The weight of a subsegment containing the elements (Pl,Pl+1,…,Pr) is defined as follows:
W(l,r)=(r−l+1)⋅minl≤i≤r(Pi)
where 1≤l≤r≤N and minl≤i≤r(Pi) denotes the minimum element of the subsegment.

You are given two integers N and X. You need to determine if there exists a permutation of length N such that it contains at least one subsegment having weight X?

Input Format
The first line contains an integer T - the number of test cases. The T test cases then follow.
The first and only line of each test case contains two space-separated integers N,X - the length of the permutation and the weight parameter mentioned in the question respectively.
Output Format
For each test case, print YES if there exists a permutation of length N having at least one subsegment with a weight of X, otherwise print NO.

You may print each character of Yes and No in uppercase or lowercase (for example, yes, yEs, YES will be considered identical).

Constraints
1≤T≤104
1≤N≤105
1≤X≤1010
Sum of N over all test cases does not exceed 3⋅105.
Sample Input 1 
4
3 2
3 5
5 6
4 10
Sample Output 1 
YES
NO
YES
NO
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
	cin >> t;
	
	while (t--) {
	    long long n, x;
	    cin >> n >> x;
	    
	    bool flag = false;
	    for (long long i = 1; i <= n; i++) {
	        if (x%i == 0 && (x/i) <= (n-i+1))
	            flag = true;
	    }
	    cout << (flag ? "YES": "NO") << "\n";
	}
	return 0;
}
