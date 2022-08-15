/*
You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

 

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
*/

string removeDuplicates(string s, int k) {
    vector<pair<char, int>> v = {{'#', 0}};
    
    for (char c : s) {
        if (v.back().first != c)
            v.push_back({c, 1});
        else {
            ++v.back().second;
            if (v.back().second == k)
                v.pop_back();
        }
    }
    
    string res;
    for (auto & p : v)
        res.append(p.second, p.first);
    return res;
}

// OR

string removeDuplicates(string s, int k) {
    int i = 0, n = s.length();
    vector<int> cnt(n, 0);
    
    for (int j = 0; j < n; j++, i++) {
        s[i] = s[j];
        cnt[i] = (i > 0 && s[j] == s[i-1] ? cnt[i-1]+1 : 1);
        
        if (cnt[i] == k)
            i -= k;
    }
    
    return s.substr(0, i);
}
