/*
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

 Example 1:

 Input:
 N = 6
 arr[] = {3,0,0,2,0,4}
 Output:
 10
*/

#include <bits/stdc++.h>

using namespace std;


int main() {

	int n = 6;
	int arr[] = {3,0,0,2,0,4};

	int left_max = 0, right_max = 0;
	int i = 0, j = n - 1;
	int result = 0;

	while (i <= j) {
		if (arr[i] < arr[j]) {
			if (arr[i] > left_max)
				left_max = arr[i];
			else
				result += left_max - arr[i];
			i++;

		} else {
			if (arr[j] > right_max)
				right_max = arr[j];
			else
				result += right_max - arr[j];
			j--;
		}
	}

	cout << result;

	return 0;
}


