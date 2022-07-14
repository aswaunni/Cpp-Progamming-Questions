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
    unordered_map<char, int> m;
    for (auto& a : t)
        m[a]++;
    
    int i = 0, j = 0;
    int n = s.length();
    int start = 0, ans = INT_MAX;
    int count = t.size();
    
    while (j < n) {
        if (m.count(s[j])) {
            if (m[s[j]] > 0)
                count--;
            m[s[j]]--;
        }
        j++;
        
        while (count == 0) {
            if (ans > (j-i)) {
                ans = j-i;
                start = i;
            }
            if (m.count(s[i])) {
                if (m[s[i]] == 0)
                    count++;
                m[s[i]]++;
            }
            i++;
        }
    }
    return (ans == INT_MAX ? "" : s.substr(start, ans));
    
}
