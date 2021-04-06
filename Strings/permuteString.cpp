/*
Given a string S. The task is to print all permutations of a given string.

 
 
 Example 1:
 
 Input: ABC
 Output:
 ABC ACB BAC BCA CAB CBA
 Explanation:
 Given string ABC has permutations in 6 
 forms as ABC, ACB, BAC, BCA, CAB and CBA .
 
 */
 
#include <bits/stdc++.h>

using namespace std;

void permute(string s, int l, int r)
{
	if (l == r)
		cout << s << " ";
	else {
		for (int i = l; i <= r; i++) {
			swap(s[l], s[i]);

			permute(s, l+1, r);

//			swap(s[l], s[i]);
		}
	}
}
int main() {

	string s = "ABC";
	int n = s.length();
	permute(s, 0, n-1);

	return 0;
}
