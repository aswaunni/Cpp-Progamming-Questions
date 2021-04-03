/*
   Given a sorted array of positive integers, rearrange the array alternately i.e first element should be the maximum value, second minimum value, third-second max, fourth-second min and so on. 
Examples:


Input: arr[] = {1, 2, 3, 4, 5, 6, 7} 
Output: arr[] = {7, 1, 6, 2, 5, 3, 4}
Input: arr[] = {1, 2, 3, 4, 5, 6} 
Output: arr[] = {6, 1, 5, 2, 4, 3} 

The idea is to use multiplication and modular trick to store two elements at an index. 


even index : remaining maximum element.
odd index  : remaining minimum element.

max_index : Index of remaining maximum element
(Moves from right to left)
min_index : Index of remaining minimum element
(Moves from left to right)

Initialize: max_index = 'n-1'
min_index = 0  
max_element = arr[max_index] + 1 //can be any element which is more than the maximum value in array

For i = 0 to n-1            
If 'i' is even
arr[i] += arr[max_index] % max_element * max_element 
max_index--     
ELSE // if 'i' is odd
arr[i] +=  arr[min_index] % max_element * max_element
min_index++
How does expression “arr[i] += arr[max_index] % max_element * max_element” work ? 
The purpose of this expression is to store two elements at index arr[i]. arr[max_index] is stored as multiplier and “arr[i]” is stored as remainder. For example in {1 2 3 4 5 6 7 8 9}, max_element is 10 and we store 91 at index 0. With 91, we can get original element as 91%10 and new element as 91/10.

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

	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);

	print(arr, n);

	int max_i = n-1, min_i = 0, max_element = arr[max_i] + 1;

	for (int i = 0; i < n; i++) {
		if (i%2 == 0) {
			arr[i] += arr[max_i]%max_element * max_element;
			max_i--;
		} else {
			arr[i] += arr[min_i]%max_element * max_element;
			min_i++;
		}
	}

	for (int i = 0; i < n; i++)
		arr[i] /= max_element;

	print(arr, n);

	return 0;
}


