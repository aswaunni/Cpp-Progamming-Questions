/*
Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each the array element between two given indices, inclusive. Once all operations have been performed, return the maximum value in the array.

Sample Input
5 3
1 2 100
2 5 100
3 4 100

Sample Output
200

Explanation
After the first update the list is 100 100 0 0 0.
After the second update list is 100 200 100 100 100.
After the third update list is 100 200 200 200 100.

Solution
e[a, b] and a value k we need to add k to all the numbers whose indices are in the range from [a, b].
We can do an O(1) update by adding k to index a and add -k to index (b+1).
Doing this kind of update, the ith number in the array will be prefix sum of array from index 1 to i because we are adding k to the value at index a and subtracting k from the value at index b+1 and taking prefix sum will give us the actual value for each index after m operations .
So, we can do all  updates in O(m) time. Now we have to check the largest number in the original array. i.e. the index i such that prefix sum attains the maximum value.
We can calculate all prefix sums as well as maximum prefix sum in O(n) time which will execute in time.
*/

//Method 1

long arrayManipulation(int n, vector<vector<int>> queries) {
	vector<long> arr(n+1, 0);

	for (auto& a : queries) {
		int value = a[2];
		arr[a[0] - 1] += value;
		arr[a[1]] += -1*value;
	}

	long result = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		result = max(result, sum);
	}
	return result;
}

//Method 2

long arrayManipulation(int n, vector<vector<int>> queries) {
	vector<pair<int, int>> m;

	for (auto& a : queries) {
		int value = a[2];
		m.push_back(make_pair(a[0], value));
		m.push_back(make_pair(a[1]+1, -1*value));
	}

	sort(m.begin(), m.end());

	long result = 0, sum = 0;
	for (auto& a : m) {
		sum += a.second;
		result = max(result, sum);
	}
	return result;
}

