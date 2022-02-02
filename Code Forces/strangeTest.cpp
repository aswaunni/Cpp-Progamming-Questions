/*
Igor is in 11th grade. Tomorrow he will have to write an informatics test by the strictest teacher in the school, Pavel Denisovich.

Igor knows how the test will be conducted: first of all, the teacher will give each student two positive integers a and b (a<b). After that, the student can apply any of the following operations any number of times:

a:=a+1 (increase a by 1),
b:=b+1 (increase b by 1),
a:=a | b (replace a with the bitwise OR of a and b).
To get full marks on the test, the student has to tell the teacher the minimum required number of operations to make a and b equal.

Igor already knows which numbers the teacher will give him. Help him figure out what is the minimum number of operations needed to make a equal to b.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). Description of the test cases follows.

The only line for each test case contains two integers a and b (1≤a<b≤106).

It is guaranteed that the sum of b over all test cases does not exceed 106.

Output
For each test case print one integer — the minimum required number of operations to make a and b equal.

Example
inputCopy
5
1 3
5 8
2 5
3 19
56678 164422
outputCopy
1
3
2
1
23329
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(int a, int b)
{
	int ret = a|b, x = 0;
	for (int i = 20; i >= 0; i--) {
		if ((b>>i)&1) {
			x |= (1<<i);
		} else {
			ret = min(ret, a|(x | (1<<i)));
		}
	}
	return ret;
}

int main ()
{
    int t;
	cin >> t;
	
	while (t--) {
        int a, b;
		cin >> a >> b;
		
		int ans = b-a;
		int count = 0;
		while (a <= b) {
			ans = min(ans, solve(a, b) - b + count + 1); // +1 for xor operation
			count++;
			a++;
		}
		cout << ans << "\n";
	}
	return 0;
}
