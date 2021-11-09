/*
Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:

Input:
s = V
Output: 5
Example 2:

Input:
s = III 
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

int value(char r)
{
	switch(r) {
		case 'I' :
			return 1;
		case 'V' :
			return 5; 
		case 'X' :
			return  10;
		case 'L' :
			return  50;
		case 'C' :
			return  100;
		case 'D' : 
			return  500;
		case 'M' : 
			return  1000;
		default :
			return 0;
	}
}

int main() {
	string s = "CD";
	int n  = s.length();
	int result = 0;

	for (int i = 0; i < n; i++) {
		int s1 = value(s[i]);
		if (i+1 < n) {
			int s2 = value(s[i+1]);
			if (s1 >= s2) {
				result += s1;
			} else {
				result += s2 - s1;
				i++;
			}
		} else
			result += s1;
	}

	cout << result;

	return 0;
}

//OR

int romanToInt(string s) {
    map<char,int> mp;
    int n = s.length();

    mp['M']=1000;mp['D']=500;mp['C']=100;mp['L']=50;
    mp['X']=10;mp['V']=5;mp['I']=1;

    int ans=0;

    for(int i = 0; i < n-1; i++) {
	    if(mp[s[i]] < mp[s[i+1]])
		    ans=ans-mp[s[i]];
	    else 
		    ans = ans+mp[s[i]];
    }
    ans += mp[s[n-1]];
    return ans;  
}
