/*
Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

 

 Example 1:

 Input:
 N = 4
 A[] = {4, 2, 5, 7}
 Output:
 5
 Explanation:
 Elements on left of 5 are smaller than 5
 and on right of it are greater than 5.
  

  Example 2:

  Input:
  N = 3
  A[] = {11, 9, 12}
  Output:
  -1

  An Efficient Solution can solve this problem in O(n) time using O(n) extra space. Below is detailed solution.

  Create two arrays leftMax[] and rightMin[].
  Traverse input array from left to right and fill leftMax[] such that leftMax[i] contains maximum element from 0 to i-1 in input array.
  Traverse input array from right to left and fill rightMin[] such that rightMin[i] contains minimum element from to n-1 to i+1 in input array.
  Traverse input array. For every element arr[i], check if arr[i] is greater than leftMax[i] and smaller than rightMin[i]. If yes, return i.

*/

#include <bits/stdc++.h>

using namespace std;


int main() {
	int n = 4;
	int arr[] = {4, 2, 5, 9, 7, 8};

	int leftMax[n], rightMin[n];
	leftMax[0] = INT_MIN;
	rightMin[n-1] = INT_MAX;

	for (int i = 1; i < n; i++)
		leftMax[i] = max(leftMax[i-1], arr[i-1]);

	for (int i = n-2; i >=0; i--)
		rightMin[i] = min(rightMin[i+1], arr[i+1]);

	for (int i = 1; i < n-1; i++) {
		if (leftMax[i] <= arr[i] && arr[i] <= rightMin[i]) {
			cout << arr[i];
			break;
		}
	}

	return 0;
}
