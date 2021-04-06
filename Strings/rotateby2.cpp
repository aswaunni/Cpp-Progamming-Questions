/*
Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating another string 'a' by exactly 2 places.

Example 1:

Input:
a = amazon
b = azonam
Output: 1
Explanation: amazon can be rotated anti
clockwise by two places, which will make
it as azonam
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	string str1 = "amazon";
	string str2 = "azonam";
	if (str1.length() != str2.length())
		return false;
	if(str1.length() < 2)
		return (str1 == str2);


	string c, ac;
	int n = str1.length();
	c = str1.substr(n-2, 2) + str1.substr(0, n-2);
	ac = str1.substr(2, n-2) + str1.substr(0, 2);

	cout << (str2 == c || str2 == ac);
}
