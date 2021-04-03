/*
Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.
*/

#include <bits/stdc++.h>

using namespace std;

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main() {

	int n = 5, k = 3;
	int arr[] = {1,2,3,4,5};
	print(arr, n);

	for (int i = 0; i < n; i += k) {
		int left = i;
		int right = min(i + k -1, n - 1);

		while (left < right) 
			swap(arr[left++], arr[right--]);
	}

	print(arr, n);

	return 0;
}



