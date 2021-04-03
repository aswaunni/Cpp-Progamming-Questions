/*
Given an array arr of N integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2, otherwise false.

Example 1:

Input:
N = 5
Arr[] = {3, 2, 4, 6, 5}
Output: Yes
Explanation: a=3, b=4, and c=5 forms a
pythagorean triplet.
Example 2:

Input:
N = 3
Arr[] = {3, 8, 5}
Output: No
Explanation: No such triplet possible.
*/

#include <bits/stdc++.h>

using namespace std;


int main() {

	int n = 5;
	int arr[] = {3, 2, 4, 6, 5};

	int k = n - 1;
	int i = 0, j = k - 1;

	sort(arr, arr+n);

	while (k > 1) {
		int x = arr[i]*arr[i];
		int y = arr[j]*arr[j];
		int z = arr[k]*arr[k];
		if (x + y == z){
			cout << arr[i] << " " << arr[j] << " " << arr[k] << "\n";
			i++;
			j--;
		} else if (x + y < z)
			i++;
		else if (x + y > z)
			j--;

		if (i >= j) {
			k--;
			i = 0;
			j = k-1;
		}

	}

	return 0;
}


