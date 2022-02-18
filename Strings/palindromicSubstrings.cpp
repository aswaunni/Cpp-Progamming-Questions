/*
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

int expandAroundCenter(int l, int r, string s) {
    int count = 0;
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
        --l;
        ++r;
        ++count;
    }
    return count;
}

int countSubstrings(string s) {
    if (s.length() < 1) return 0;
    
    int ans = 0;
    for (int i = 0; i < s.length(); ++i)
        ans += (expandAroundCenter(i, i, s) + expandAroundCenter(i, i+1, s));
    return ans;
}
