/*
   Given a matrix of size R*C. Traverse the matrix in spiral form.

   Example 1:

Input:
R = 4, C = 4
matrix[][] = {{1, 2, 3, 4},
{5, 6, 7, 8},
{9, 10, 11, 12},
{13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
 */

#include <bits/stdc++.h>

using namespace std;
#define R 3
#define C 6

void spiralPrint(int r, int c, int arr[R][C]) 
{
	int k = 0, l = r-1, m = 0, n = c-1;
	int i;

	while (k <= l && m <= n) {

		for (i = m; i <= n; i++)
			cout << arr[k][i] << " ";
		k++;

		for (i = k; i <= l; i++)
			cout << arr[i][n] << " ";
		n--;

		if (k <= l) {
			for (i = n; i >= m; i--)
				cout << arr[l][i] << " ";
			l--;
		}

		if (m <= n) {
			for (i = l; i >=k; i--)
				cout << arr[i][m] << " ";
			m++;
		}
	}
}

int main() {
	int a[R][C] = { { 1, 2, 3, 4, 5, 6 },
		{ 7, 8, 9, 10, 11, 12 },
		{ 13, 14, 15, 16, 17, 18 } };

	spiralPrint(R, C, a);

	return 0;
}
