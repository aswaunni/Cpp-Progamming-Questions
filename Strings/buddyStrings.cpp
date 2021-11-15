/*
Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
 

Example 1:

Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
*/


bool buddyStrings(string s, string goal) {
    
    if (s.size() != goal.size())
        return false;
    
    if (s == goal) {
        set<char> x;
        for (int i = 0; i < s.size(); i++)
            x.insert(s[i]);
        if (x.size() == s.size())
            return false;
        return true;
    }
    
    vector<int> diffs;
    int numDiffs = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != goal[i]) {
            numDiffs++;
            diffs.push_back(i);
        }
    }
            
    if (numDiffs != 2)
        return false;
    
    if (s[diffs[1]] == goal[diffs[0]] && s[diffs[0]] == goal[diffs[1]])
        return true;
    return false;
}
