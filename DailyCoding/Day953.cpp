/******************************************************************************
[MEDIUM]

This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main(){
    vector<int> v {2, 4, 6, 2, 5};
    int n = v.size();
    
	vector<int> dp(n+1, 0);
	for (int i = 0; i < n; i++)
	    dp[i+1] = max(dp[i], (i > 0 ? dp[i-1] : 0) + v[i]);
	    
	cout << dp[n];
	
	return 0;
}
