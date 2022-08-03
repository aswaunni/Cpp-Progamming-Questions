/*
Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
Example 2:

Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
*/

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> ans;
    string nPattern = normalize(pattern);
    for (auto& a : words) {
        if (normalize(a) == nPattern)
            ans.push_back(a);
    }
    return ans;
}

string normalize(string s) {
    char c = 'a';
    unordered_map<char, char> m;
    for (auto& a : s)
        if (!m.count(a))
            m[a] = c++;
    
    for (auto& a : s)
        a = m[a];
    return s;
}
