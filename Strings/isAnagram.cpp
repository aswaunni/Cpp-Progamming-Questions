/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/

bool isAnagram(string s, string t) {
    vector<int> v(26, 0);
    
    if (s.length() != t.length()) return false;
    
    for(int i = 0; i < s.length(); i++) {
        v[s[i] - 'a']++;
        v[t[i] - 'a']--;
    }
    
    for (auto& a : v) {
        if (a != 0)
            return false;
    }
    return true;
}
