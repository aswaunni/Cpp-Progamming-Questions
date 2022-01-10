#include <bits/stdc++.h>

using namespace std;


int main() {

	int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
	int n = sizeof(arr)/sizeof(*arr);
	int sum = 23;
	int start = 0;
	int maxSum = 0;
	for (int i = 0; i <= n; i++) {
		while (maxSum > sum && start < i-1)
			maxSum -= arr[start++];

		if (maxSum == sum) {
			cout << start << " " << i-1;
			break;
		} 
		if (i < n)
			maxSum += arr[i];
	}

	return 0;
}
