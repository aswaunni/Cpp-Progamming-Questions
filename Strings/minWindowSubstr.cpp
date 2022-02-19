/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/

string minWindow(string s, string t) {
    if (s.length() < t.length())
        return "";
    
    unordered_map<char, int> m, temp;
    for (auto& a : t) ++m[a];
    
    int l = 0, r = 0;
    
    int start = 0, ans = INT_MAX, count = 0;
    while (r < s.length()) {
        if (m.count(s[r])) {
            ++temp[s[r]];
            if (temp[s[r]] == m[s[r]])
                ++count;
        }
        ++r;
        
        while (count == m.size()) {
            if (ans > (r - l)) {
                ans = r - l;
                start = l;
            }
            if (m.count(s[l])) {
                --temp[s[l]];
                if (temp[s[l]] < m[s[l]])
                    --count;
            }
            ++l;
        }
    }
    return (ans == INT_MAX ? "" : s.substr(start, ans));
}
