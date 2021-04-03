/*
   Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
   The solution can be further optimized by observing that while traversing the two sorted arrays parallelly, if we encounter the jth second array element is smaller than ith first array element, then jth element is to be included and replace some kth element in the first array. This observation helps us with the following algorithm




   Algorithm


   1) Initialize i,j,k as 0,0,n-1 where n is size of arr1 

   2) Iterate through every element of arr1 and arr2 using two pointers i and j respectively

   if arr1[i] is less than arr2[j]

   increment i

   else

   swap the arr2[j] and arr1[k]

   increment j and decrement k



   3) Sort both arr1 and arr2 
 */

#include <bits/stdc++.h>

using namespace std;


int main() {

	int n = 4, arr1[] = {1, 3, 5, 7};
	int m = 5, arr2[] = {0, 2, 6, 8, 9};

	int i = 0, j = 0, k = n-1;

	while (i <= k and j < m) {
		if (arr1[i] < arr2[j])
			i++;
		else
			swap(arr2[j++], arr1[k--]);
	}	

	sort(arr1, arr1 + n);
	sort(arr2, arr2 + m);

	for (auto& a : arr1)
		cout << a << " ";

	cout << "\n";

	for (auto& a : arr2)
		cout << a << " ";

	return 0;
}
