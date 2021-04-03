/*
Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.
1 5 3 2 4

1 2 3 4 5
j     k i
  j k   i
  j   k i
  j k i

*/

#include <bits/stdc++.h>

using namespace std;


int main() {

	int arr[] = {1, 5, 3, 2, 4};
	int n = sizeof(arr)/sizeof(*arr);

	sort(arr, arr+n);

	int i = n-1;
	int j = 0;
	int k = i - 1;

	while (i > 1) {
		if (arr[j] + arr[k] < arr[i])
			j++;

		if (arr[j] + arr[k] > arr[i])
		        k--;

		if (arr[j] + arr[k] == arr[i]) {
			cout << arr[j] << " " << arr[k] << " " << arr[i] << endl;
			j++;
			k--;
		}

		if (j >= k) {
			i--;
			j = 0;
			k = i - 1;
		}
	}

	return 0;
}
