/*
   Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
Initialize:

max_so_far = INT_MIN

max_ending_here = 0



Loop for each element of the array

(a) max_ending_here = max_ending_here + a[i]

(b) if(max_so_far < max_ending_here)

max_so_far = max_ending_here

(c) if(max_ending_here < 0)

max_ending_here = 0

return max_so_far
 */

#include <bits/stdc++.h>

using namespace std;


int main() {

	int arr[] = {-2, -3, 4, -2, -1, 1, 5, -3};
	int n = sizeof(arr)/sizeof(*arr);

	int max_so_far = INT_MIN;
	int max_ending_here = 0;

	for (int i = 0; i < n; i++) {
		max_ending_here += arr[i];

		if (max_ending_here > max_so_far)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}

	cout << max_so_far;

	return 0;
}


