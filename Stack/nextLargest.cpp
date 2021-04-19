/*
Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

Example 1:

Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
since it doesn't exist, it is -1.
*/

#include <bits/stdc++.h>
using namespace std;
vector<long long> nextLargerElement(vector<long long> arr, int n){

	stack<long> s;
	map<long, long> m;

	for (int i = 0; i < n; i++) {
		if (s.empty()) {
			s.push(arr[i]);
			continue;
		}

		while (!s.empty() && s.top() < arr[i]) {
			m[s.top()] = arr[i];
			s.pop();
		}

		s.push(arr[i]);
	}

	while(!s.empty()) {
		m[s.top()] = -1;
		s.pop();
	}

	for(int i = 0; i < n; i++) {
		arr[i] = m[arr[i]];
	}
	return arr;
}

void print(vector<long long> v)
{
	for(auto& a : v)
		cout << a << " ";
	cout << "\n";
}

int main() {

	vector<long long> v = {2, 3, 8, 1};
	print(v);

	vector<long long> res = nextLargerElement(v, 4);

	print(res);

	return 0;
}
