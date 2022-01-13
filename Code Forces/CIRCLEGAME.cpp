/*
Aujasvit and the Circle Game Problem Code: CIRCLEGAME

Aujasvit just came up with a new game to play with his friends. N people stand in a circle, each assigned an index from 1 to N in clockwise order. Then the following operation is done N−1 times.

The person with the lowest index holds a coin.
Then, the coin then moves to the next person clockwise M−1 times.
Then, the person who is holding the coin is removed from the circle.
The last person remaining after N−1 operations is the winner.

Aujasvit has already decided on the integer M to be used in the game. Before inviting people to play his game, Aujasvit wants to know the winner if the game has 1 player, 2 players, 3 players, …, X players. That is, you need to output the winner when N=1,N=2,...,N=X.

Input Format
The first line of each input contains T - the number of test cases. The test cases then follow.
The only line of each test case contains two space-separated integers M and X.
Output Format
For each testcase, output X integers A1,A2,…,AX, where Ai is the index of the winner if i people are playing this game.

Constraints
1≤T≤1000
1≤M≤109
1≤X≤10000
Sum of X over all testcases is not more than 5⋅105
Sample Input 1 
1
2 3
Sample Output 1 
1 1 1

//Explanation

For N ≤ X, consider
f(N)= M % N, 
if M % N = 0, f(N) = N

f(N) gives the position of the index that is reached (removed) after the operation occurs once out of the N-1 times. This means we can now compare it to when the game is played with N-1 players.
Consider winner from N players as g(N).
If g(N-1) < f(N), it means that g(N) would be the same as that of g(N−1). This is because if you remove a player that was ahead of g(N−1), the difference won’t affect the winner for a circle of NN players.

However if g(N-1) >= f(N), that means the circle has changed and g(N) will be g(N-1) + 1. We will take the base case as g(1) = 1 because 0 operations will be performed in this case.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int m, x;
	    cin >> m >> x;
	    
	    vector<int> v(x+1);
	    v[1] = 1;
	    cout << v[1] << " ";
	    for (int i = 2; i <= x; i++) {
	        int temp = m%i;
	        if (temp == 0)
	            temp = i;
	            
	        if (v[i-1] < temp)
	            v[i] = v[i-1];
	        else
	            v[i] = v[i-1]+1;
	        cout << v[i] << " ";
	    }
	    cout << "\n";
	}
	return 0;
}
