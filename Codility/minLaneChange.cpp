/*

For a navigation system, you are to implement lane change instructions. The road is represented as n segments. Lanes are represented by integers 0 <= i < 8. Each segment can contain an arbitrary subset of lanes. The driver can navigate from lane i in segment s to either lane i-1, i or i+1 in segment s+1(if these lanes exist in that segment). Navigating from lane i to a lane other than i in the next segment counts as a lane change.

Write a function:
	int solution(vector<int> &A);

that, given a zero-indexed array A of n integers encoding the lanes present, returns an integer that indicates the minimum possible number of lane changes to get from any lane on the forst segment to any lane on the last segment or returns -1 if not possile to reach the last segment.

The array A[s], 0 <= s < n, encodes the lanes present on the segment s:bit i (0 <= i < 8) is set in A[s] if and only if lane i is present in segment s. Bits higher than 7  are always 0.

Assumptions:
- n integer within [1....100,000]
- each element in A is integer within [0...255]

Example:
A = [7,11,10,4] sould return 1.

0111 segment 0
1011 segment 1
1010 segment 2
0100 segment 3

The path with least lane changes stays on lane 1 for te sgments 0, 1, 2 and then switches to lane 2.



*/

#include <bits/stdc++.h>
using namespace std;

#define N 8

int m = INT_MAX;

void lane(int i, int j, vector<bitset<N>>& arr, int n, int count)
{
	if (i == n-1) {
		m = min(m, count);
		return;
	}

	if ((j-1) >= 0 && arr[i+1][j-1])
		lane(i+1, j-1, arr, n, count+1);

	if (arr[i+1][j])
		lane(i+1, j, arr, n, count);

	if ((j+1) < N && arr[i+1][j+1])
		lane(i+1, j+1, arr, n, count+1);

}

int main()
{
	vector<int> inputArr = {7, 13, 10, 4}; // {00000111, 00001101, 00001010, 00000100}
	int n = inputArr.size();

	vector<bitset<N>> arr;

	for (auto& a : inputArr) {
		bitset<N> b(a);
		arr.push_back(b);
	}

	for (int j = 0; j < N-1; ++j) {
		if (arr[0][j]) {
			lane(0, j, arr, n, 0);
			if (m == 0)
				break;
		}
	}

	cout << (m == INT_MAX ? -1 : m);
	return 0;
}

