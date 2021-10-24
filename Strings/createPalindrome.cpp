/*
Grandma Capa has decided to knit a scarf and asked Grandpa Sher to make a pattern for it, a pattern is a string consisting of lowercase English letters. Grandpa Sher wrote a string s of length n.
Grandma Capa wants to knit a beautiful scarf, and in her opinion, a beautiful scarf can only be knit from a string that is a palindrome. She wants to change the pattern written by Grandpa Sher, but to avoid offending him, she will choose one lowercase English letter and erase some (at her choice, possibly none or all) occurrences of that letter in string s.
She also wants to minimize the number of erased symbols from the pattern. Please help her and find the minimum number of symbols she can erase to make string s a palindrome, or tell her that it's impossible. Notice that she can only erase symbols equal to the one letter she chose.
A string is a palindrome if it is the same from the left to the right and from the right to the left. For example, the strings 'kek', 'abacaba', 'r' and 'papicipap' are palindromes, while the strings 'abb' and 'iq' are not.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases. The next 2⋅t lines contain the description of test cases. The description of each test case consists of two lines.
The first line of each test case contains a single integer n (1≤n≤105) — the length of the string.
The second line of each test case contains the string s consisting of n lowercase English letters.
It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case print the minimum number of erased symbols required to make the string a palindrome, if it is possible, and −1, if it is impossible.

Example
inputCopy
5
8
abcaacab
6
xyzxyz
4
abba
8
rprarlap
10
khyyhhyhky
outputCopy
2
-1
0
3
2
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s;
        cin >> n >> s;
      
        int ans = -1;
        for (char c = 'a'; c <= 'z'; c += 1) {
            int pans = 0;
            int L = 0, R = n - 1;
            while (L < R) {
                if (s[L] == s[R]) {
                    L += 1;
                    R -= 1;
                }
                else if (s[L] == c) {
                    pans += 1;
                    L += 1;
                }
                else if (s[R] == c) {
                    pans += 1;
                    R -= 1;
                }
                else {
                    pans = -1;
                    break;
                }
            }
            if (pans != -1 and (ans == -1 or pans < ans)) ans = pans;
        }
        cout << ans << "\n";
    }
    return 0;
}
