/*
Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Example 1:

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
	public:
		vector <int> max_of_subarrays(int *arr, int n, int k){
			deque<int> q(k);
			vector<int> res;

			int i;

			for (i = 0; i < n; ++i) {
				if (i >= k) {
					res.push_back(arr[q.front()]);

					if (!q.empty() && q.front() == i-k)
						q.pop_front();
				}
				while (!q.empty() && arr[i] >= arr[q.back()])
					q.pop_back();
				q.push_back(i);
			}
			res.push_back(arr[q.front()]);
			return res;
		}
};

// { Driver Code Starts.

int main() {

	int t;
	cin >> t;

	while(t--){

		int n, k;
		cin >> n >> k;

		int arr[n];
		for(int i = 0;i<n;i++) 
			cin >> arr[i];
		Solution ob;
		vector <int> res = ob.max_of_subarrays(arr, n, k);
		for (int i = 0; i < res.size (); i++) 
			cout << res[i] << " ";
		cout << endl;

	}

