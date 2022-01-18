/*
You are given a sequence A of N integers such that every element is a non-negative power of 2.

A sequence is called good if its sum is a non-negative power of 2. You would like to turn A into a good sequence.

To achieve this, you can perform the following operation on A:

Pick a non-empty subsequence of A, pick a positive integer X such that X≤230, and multiply every element of this subsequence by X.
Find the minimum number of operations required to turn A into a good sequence. Also, find one sequence of operations which does this. If there are multiple possible answers, you may find any of them.

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line of each test case contains N space-separated integers A1,A2,…,AN.
Output Format
For each test case, print the answer in the following format:

First, print one line containing an integer M, denoting the minimum number of moves required.
Then, print 2M lines describing M operations.
Each operation is described by 2 lines.
On the first line, print two space-separated integers K and X, denoting the size of the subsequence and the multiplier for this operation.
On the second line, print K distinct space-separated integers denoting the indices of the elements chosen to be multiplied in this operation. These K integers can be printed in any order.
Constraints
1≤T≤1000
1≤N≤100
1≤Ai≤220
Subtasks
Subtask #1 (100 points): Original constraints

Sample Input 1 
2
4
4 8 4 32
3
2 2 4
Sample Output 1 
1
3 2
1 2 3
0

//HINT
Required number of operations is either 0 or 1.
If the sequence is already good, the answer is 0.
If the sequence is not good, we require only 1 operation.
Let S be the sum of the sequence (where S is not a power of 2) and r be the smallest integer such that S < 2^r.
In one operation, we choose the smallest number of the sequence M, and multiply it with X = (2^r - (S - M))/X. 

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
	    int mn = INT_MAX;
	    int idx = 0;
	    int sum = 0;
	    
	    for (int i = 0; i < n; i++) {
	        cin >> v[i];
	        if (v[i] < mn) {
	            mn = v[i];
	            idx = i+1;
	        }
	        sum += v[i];
	    }
	    
	    if ((sum & (sum-1)) == 0) {
	        cout << "0\n";
	        continue;
	    }
	    
	    int bits = (int)log2(sum) + 1;
	    int target = (1 << bits);
	    int x = (target - sum + mn) / mn;
	    cout << "1\n";
	    cout << "1 " << x << "\n";
	    cout << idx << "\n";

	}
	return 0;
}
