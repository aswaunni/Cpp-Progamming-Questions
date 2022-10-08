/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*/

bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length())
        return false;
    vector<int> count(26, 0);
    for (auto& c : s1)
        count[c-'a']++;

    int i = 0;
    for (int j = 0; j < s2.length(); j++) {
        char c = s2[j];
        count[c-'a']--;

        while (count[c-'a'] < 0)
            count[s2[i++]-'a']++;

        if (j-i+1 == s1.length())
            return true;
    }
    return false;
}
