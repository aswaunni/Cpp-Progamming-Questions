/*
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
*/
int numMatchingSubseq(string s, vector<string>& words) {
    vector<pair<string, int>> v[26];
    
    for (auto& w : words)
        v[w[0] - 'a'].push_back({w, 0});
    
    int cnt = 0;
    for (auto& c : s) {
        auto t = v[c - 'a'];
        v[c - 'a'].clear();
        
        for (auto& [a, i] : t) {
            ++i;
            if (i == a.length())
                ++cnt;
            else
                v[a[i] - 'a'].push_back({a, i});
        }
    }
    return cnt;
}

// OR

int numMatchingSubseq(string s, vector<string>& words) {
    vector<vector<int>> v(26);
    
    for (int i = 0; i < s.length(); i++)
        v[s[i] - 'a'].push_back(i);

    int cnt= 0;
    for (auto& word : words) {
        int lastIdx = -1;
        int i = 0;
        for (; i < word.length(); ++i) {
            int c = word[i] - 'a';
            auto x = upper_bound(v[c].begin(), v[c].end(), lastIdx);
            
            if (x == v[c].end())
                break;
            
            lastIdx = *x;
        }
        if ( i == word.length())
            cnt++;
    }
    return cnt;
}
