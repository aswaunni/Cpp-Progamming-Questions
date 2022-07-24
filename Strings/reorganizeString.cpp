/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
*/

string reorganizeString(string s) {
    map<int, int> m;
    bool flag = false;
    int mx = 0, n = s.length();
    int ch;
    
    for (int i = 0; i < n; i++) {
        if (i > 0 && s[i] == s[i-1]) {
            flag = true;
        }
        m[s[i] - 'a']++;
        if (m[s[i] - 'a'] > mx) {
            mx = m[s[i] - 'a'];
            ch = s[i] - 'a';
        }
    }
    
    if (!flag)
        return s;
    if (mx > (n+1)/2)
        return "";
    
    string ans(n, ' ');
    int itr = 0;
    
    while (m[ch]) {
        ans[itr] = ch + 'a';
        m[ch]--;
        itr += 2;
    }
    
    for (auto& [k, v] : m) {
        while (v) {
            if (itr >= n)
                itr = 1;
            ans[itr] = k + 'a';
            v--;
            itr += 2;
        }
    }

    return ans;
}
