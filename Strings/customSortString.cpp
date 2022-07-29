/*
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

 

Example 1:

Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
Example 2:

Input: order = "cbafg", s = "abcd"
Output: "cbad"
*/

        
		
string customSortString(string order, string s) {
    vector<int> v(26, 0);
    for (auto& c : s)
        v[c-'a']++;
    
    string ans;
    for (auto& c : order) {
        while((v[c-'a']--) > 0)
            ans += c;
    }
    
    for (int i = 0; i < 26; i++) {
        while ((v[i]--) > 0)
            ans += 'a' + i;
    }        
    
    return ans;
}

// OR

string customSortString(string order, string s) {
    unordered_map<int, int> m;
    for (int i = 0; i < order.size(); i++)
        m[order[i]] = i;
    
    sort(s.begin(), s.end(), [&](const char& a, const char& b) {
       return m[a] < m[b];
    });
    
    return s;
}
