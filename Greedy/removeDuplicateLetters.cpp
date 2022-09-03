/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
*/

string removeDuplicateLetters(string s) {
    int n = s.length();
    vector<bool> vis(26, false);
    vector<int> last(26, 0);
    string ans;
    
    for (int i = 0; i < n; ++i)
        last[s[i]-'a'] = i;  
    
    for (int i = 0; i < n; ++i) {
        if (!vis[s[i] - 'a']) {
            while (!ans.empty() && ans.back() >= s[i] && last[ans.back() - 'a'] > i) {
                vis[ans.back()-'a'] = false;
                ans.pop_back();
            }
            
            ans += s[i];
            vis[s[i] - 'a'] = true;
        }
    }
    
    return ans;
}
