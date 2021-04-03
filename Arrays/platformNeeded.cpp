/*
Given arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms required for the railway station so that no train waits.
We are given two arrays that represent arrival and departure times of trains that stop.

Examples:
Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}
dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
Output: 3
Explantion: There are at-most three trains at a time (time between 11:00 to 11:20)

Input: arr[] = {9:00, 9:40}
dep[] = {9:10, 12:00}
Output: 1
Explantion: Only one platform is needed.

Algorithm:
Sort the arrival and departure time of trains.
Create two pointers i=0, and j=0 and a variable to store ans and current count plat
Run a loop while i<n and j<n and compare the ith element of arrival array and jth element of departure array.
if the arrival time is less than or equal to departure then one more platform is needed so increase the count, i.e. plat++ and increment i
Else if the arrival time greater than departure then one less platform is needed so decrease the count, i.e. plat++ and increment j
Update the ans, i.e ans = max(ans, plat).
*/

#include <bits/stdc++.h>

using namespace std;

int main() {

	int n = 6;
	int arr[] = {900, 940, 950, 1100, 1500, 1800};
	int dep[] = {910, 1200, 1120, 1130, 1900, 2000};

	sort(arr, arr + n);
	sort(dep, dep + n);

	int plat_needed = 1, result = 1;
	int i = 1, j = 0;

	while (i < n && j < n) {
		if (arr[i] > dep[j]) {
			result--;
			j++;
		} else {
			result++;
			i++;
		}

		plat_needed = max(result, plat_needed);
	}

	cout << plat_needed;
	return 0;
}


