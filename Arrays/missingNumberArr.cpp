/*
Given an array of size N-1 such that it can only contain distinct integers in the range of 1 to N. Find the missing element.

Approach: The length of the array is n-1. So the sum of all n elements, i.e sum of numbers from 1 to n can be calculated using the formula n*(n+1)/2. Now find the sum of all the elements in the array and subtract it from the sum of first n natural numbers, it will be the value of the missing element.

*/
#include <bits/stdc++.h>

using namespace std;


int main() {

	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = 10;

	int sum = (n*(n+1))/2;
	int sum_so_far = 0;
	for (int i = 0; i < n; i++)
		sum_so_far += arr[i];

	cout << sum - sum_so_far;

	return 0;
}


