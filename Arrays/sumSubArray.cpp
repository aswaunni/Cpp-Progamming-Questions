/*
Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.
*/

#include <bits/stdc++.h>

using namespace std;


int main() {

	int arr[] = {2, 5, 7, 5, 4, 9, 1};
	int n = sizeof(arr)/sizeof(*arr);
	int sum = 16;

	for (int i = 0; i < n; i++) {
		int j = i;
		int s = 0;
		while (s < sum && j < n)
			s += arr[j++];

		if (s == sum) {
			for (int k = i; k < j; k++)
				cout << arr[k] << " ";
			break;
		}
	}

	return 0;
}
