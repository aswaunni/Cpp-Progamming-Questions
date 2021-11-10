
//  A C++ Program to find the longest common prefix

string longestCommonPrefix(vector<string>& strs) {
    string s = *min_element(strs.begin(), strs.end());
    
    string ans = "";
    int n = strs.size();
    
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < n; j++) {
            if (s[i] != strs[j][i])
                return ans;
        }
        ans += s[i];
    }
    return ans;
}
