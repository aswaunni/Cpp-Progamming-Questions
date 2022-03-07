/*
A number is called powerful if it is a power of two or a factorial. In other words, the number m is powerful if there exists a non-negative integer d such that m=2d or m=d!, where d!=1⋅2⋅…⋅d (in particular, 0!=1). For example 1, 4, and 6 are powerful numbers, because 1=1!, 4=22, and 6=3! but 7, 10, or 18 are not.

You are given a positive integer n. Find the minimum number k such that n can be represented as the sum of k distinct powerful numbers, or say that there is no such k.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). Description of the test cases follows.

A test case consists of only one line, containing one integer n (1≤n≤1012).

Output
For each test case print the answer on a separate line.

If n can not be represented as the sum of distinct powerful numbers, print −1.

Otherwise, print a single positive integer  — the minimum possible value of k.

Example
inputCopy
4
7
11
240
17179869184
outputCopy
2
3
4
1
*/

#include <bits/stdc++.h>
using namespace std;
 
const int N = 15;
long long fact[N];
long long val[1<<N];
 
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fact[3] = 6;
  for (int i = 4; i < N; i++) {
    fact[i] = i*fact[i-1]; // get all factorials < 10^12 ie. N = 15
  }
  for (int i = 0; i < (1<<N); i++) { // find all permutaion sum of the factorials..2^N permutations. The position of1 is used to determine the different selection of permutaion
    for (int j = 3; j < N; j++) {
      if (i&(1<<j)) { // if bit set then add the factorials
        val[i] += fact[j];
      }
    }
  }
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    int ans = 1e9;
    for (int i = 0; i < (1<<N); i++) {
      if (val[i] <= n) {
        ans = min(ans, __builtin_popcountll(i) + __builtin_popcountll(n-val[i])); // number of set bits in i gives the selection in perutation of factorial and in n-val[i] gives powers of 2. 
      }
    }
    cout << ans << '\n';
  }
}
