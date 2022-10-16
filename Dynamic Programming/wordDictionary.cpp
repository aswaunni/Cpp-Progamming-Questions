/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
*/

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    
    vector<bool> dp(n+1);
    dp[n] = true;
    
    unordered_set<string> map;
    for (auto& a : wordDict)
        map.insert(a);
    
    for (int i = n-1; i >= 0; i--) {
        string sub = "";
        for (int j = i; j < n; j++) {
            sub += s[j];
            if (map.count(sub) && dp[j+1]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[0];
}

// OR (recursion)

bool helper(string A) {
    if (A.length() == 0)
        return true;
    for (int i = 1; i <= A.length(); i++) {
        if (st.count(A.substr(0, i)) && helper(A.substr(i)))
            return true;
    }
    return false;
}

int wordBreak(string A, vector<string> &B) {

    for (auto& s : B)
        st.insert(s);
    
    return helper(A);
}

unordered_set<string> st;
