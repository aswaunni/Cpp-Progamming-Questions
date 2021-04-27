/*
The problem is to count all the possible paths from top left to bottom right of a MxN matrix with the constraints that from each cell you can either move to right or down.

Example 1:

Input:
M = 3 and N = 3
Output: 6
*/

#include <bits/stdc++.h>
using namespace std;


long long  numberOfPaths(int m, int n)
{
	if (m == 1 || n == 1)
		return 1;

	return numberOfPaths(m-1, n) + numberOfPaths(m, n-1);
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
		cout << numberOfPaths(m, n)<<endl;
	}
	return 0;
}
