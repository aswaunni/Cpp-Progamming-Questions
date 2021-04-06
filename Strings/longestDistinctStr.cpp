/*
Given a string S, find length of the longest substring with all distinct characters. 

Example 1:

Input:
S = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest 
substring with all distinct characters.
â€‹Example 2:

Input: 
S = "aaa"
Output: 3
Explanation: "a" is the longest substring 
with all distinct characters.

The idea is to scan the string from left to right, keep track of the maximum length Non-Repeating Character Substring seen so far in res. When we traverse the string, to know the length of current window we need two indexes. 
1) Ending index ( j ) : We consider current index as ending index. 
2) Starting index ( i ) : It is same as previous window if current character was not present in the previous window. To check if the current character was present in the previous window or not, we store last index of every character in an array lasIndex[]. If lastIndex[str[j]] + 1 is more than previous start, then we updated the start index i. Else we keep same i.  

*/

#include <bits/stdc++.h>
using namespace std;

int longestSubstrDistinctChars (string s)
{
	int n = s.length();

	vector<int> arr(256, -1);

	int count = 0;

	int i = 0;
	for (int j = 0; j < n; j++) {
		i = max(i, arr[s[j]] + 1);
		count = max(j - i + 1, count);
		arr[s[j]] = j;
	}
	return count;
}

int main() {
	string s = "geeksforgeeks";

	cout << longestSubstrDistinctChars(s);

	return 0;
}

