/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
*/

class Solution {
public:
    vector<vector<string>> ans;
    
    bool isPalindrome(string s) {
        int l = 0, r = s.length()-1;
        while (l <= r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
    
    void solve(string s, vector<string>& v, int start) {
        if (start == s.length())
            ans.push_back(v);
        
        for (int i = 1; start+i <= s.length(); i++) {
            string x = s.substr(start, i);
            if (isPalindrome(x)) {
                v.push_back(x);
                solve(s, v, start+i);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> v;
        solve(s, v, 0);
        return ans;
    }
};
