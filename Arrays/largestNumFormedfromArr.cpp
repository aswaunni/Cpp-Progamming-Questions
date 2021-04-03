/*
Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.The result is going to be very large, hence return the result in the form of a string.

Example 1:

Input: 
N = 5
Arr[] = {3, 30, 34, 5, 9}
Output: 9534330
Explanation: Given numbers are {3, 30, 34,
5, 9}, the arrangement 9534330 gives the
largest value.
Example 2:

Input: 
N = 4
Arr[] = {54, 546, 548, 60}
Output: 6054854654
Explanation: Given numbers are {54, 546,
548, 60}, the arrangement 6054854654 
gives the largest value.
*/

#include <bits/stdc++.h>

using namespace std;

bool str_compare(string a, string b)
{
	string ab = a.append(b);
	string ba = b.append(a);

	return (ab.compare(ba) > 0 ? 1 : 0);
}

int main() {
	int n = 5;
	string arr[] = {"3", "30", "34", "5", "9"};
	sort(arr, arr+n, str_compare);

	for (auto& a : arr)
		cout << a.c_str();

	return 0;
}
