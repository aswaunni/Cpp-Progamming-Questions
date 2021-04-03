/*
   Equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes. For example, in an array A:

Example :
Input: A[] = {-7, 1, 5, 2, -4, 3, 0}
Output: 3
3 is an equilibrium index, because:
A[0] + A[1] + A[2] = A[4] + A[5] + A[6]

Input: A[] = {1, 2, 3}
Output: -1

Method 2 (Tricky and Efficient) The idea is to get the total sum of the array first. Then Iterate through the array and keep updating the left sum which is initialized as zero. In the loop, we can get the right sum by subtracting the elements one by one. Thanks to Sambasiva for suggesting this solution and providing code for this.

1) Initialize leftsum  as 0
2) Get the total sum of the array as sum
3) Iterate through the array and for each index i, do following.
a)  Update sum to get the right sum.  
sum = sum - arr[i] 
// sum is now right sum
b) If leftsum is equal to sum, then return current index. 
// update leftsum for next iteration.
c) leftsum = leftsum + arr[i]
4) return -1 
// If we come out of loop without returning then
// there is no equilibrium index
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

	int arr[] = { -7, 1, 5, 2, -4, 3, 0 };
	int n = sizeof(arr)/sizeof(arr[0]);

	print(arr, n);

	int sum = 0;
	int leftSum = 0;

	for (int i = 0; i < n; i++)
		sum += arr[i];

	for (int i = 0; i < n; i++) {
		sum -= arr[i];
		if (sum == leftSum) {
			cout << arr[i];
			break;
		}
		leftsum += arr[i];
	}

	return 0;
}


