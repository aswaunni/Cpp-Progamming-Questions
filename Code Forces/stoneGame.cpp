/*
Initially, Alice and Bob both have a bag of N stones each with every stone having a lowercase alphabet written on it. Both players know the stones of the other player.

Alice and Bob want to create a string S of length 2⋅N using the stones they have. They play a game to create the string. The rules of the game are as follows:

Initially, all the indices of S are empty.
Alice starts the game. The players take alternating turns. In each turn, the player can choose one of the stones from their bag and place it at any empty index i (1≤i≤2⋅N) of S.
The game ends when both the players have used all their stones.
Alice wants S to be as lexicographically small as possible while Bob wants S to be as lexicographically large as possible.
Find the final string S formed by characters written on stones if both Alice and Bob play optimally!

Note: A string X is lexicographically smaller than a string Y if and only if one of the following holds:

X is a prefix of Y and X≠Y
In the first position where X and Y differ, the string X has a letter that appears earlier in the alphabet than the corresponding letter in Y.
Input Format
The first line contains an integer T - the number of test cases. The description of T test cases follows:
The first line of each test case contains an integer N - the number of stones each player has.
The second line of each test case contains a string A of length N describing the stones in Alice's bag initially.
The third line of each test case contains a string B of length N describing the stones in Bob's bag initially.
Output Format
For each test case, print the final string S formed if Alice and Bob play optimally.

Constraints
1≤T≤1000
1≤N≤105
It is guaranteed that the sum of N over all test cases does not exceed 2⋅105.
Sample Input 1 
2
3
aza
abz
4
cccc
cccc
Sample Output 1 
azabza
cccccccc
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    string a, b;
	    
	    cin >> a >> b;
	    
	    sort(a.begin(), a.end());
	    sort(b.begin(), b.end(), greater<char>());
	    
	    string ans(2*n, ' ');
	    int l = 0, r = 2*n - 1;
	    int la = 0, lb = 0, ra = n-1, rb = n-1;
	    
	    for (int i = 0; i < 2*n; i++) {
	        if (i%2 == 0) {
	            if (a[la] < b[lb])
	                ans[l++] = a[la++];
	            else
	                ans[r--] = a[ra--];
	        } else {
	            if (b[lb] > a[la])
	                ans[l++] = b[lb++];
	            else
	                ans[r--] = b[rb--];
	        }
	    }
	    cout << ans << "\n";
	}
	return 0;
}
