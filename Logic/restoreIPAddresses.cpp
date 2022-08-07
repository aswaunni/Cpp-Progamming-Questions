/*
A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

 

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
*/

vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    int n = s.length();
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                for (int l = 1; l <= 3; l++) {
                    if (i+j+k+l == n) {
                        int A = stoi(s.substr(0, i));
                        int B = stoi(s.substr(i, j));
                        int C = stoi(s.substr(i+j, k));
                        int D = stoi(s.substr(i+j+k, l));
                        
                        if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
                            string tmp = to_string(A) + '.' + to_string(B) + '.' + to_string(C) + '.' + to_string(D);
                            if (tmp.length() == n+3)
                                ans.push_back(tmp);
                        }
                    }
                }
            }
        }
    }
    return ans;
}

// OR

vector<string> ans;
void helper(string s,int cnt, string a) {
    if (cnt == 4 && s.size() ==0)
        ans.push_back(a.substr(0, a.length()-1));
    for (int i = 1; i <= 3; i++) {
        if (s.length() < i)
            break;
        int x = stoi(s.substr(0, i));
        if (x > 255 || to_string(x).length() != i)
            continue;
        helper(s.substr(i), cnt+1, a+s.substr(0, i)+'.');
    }
}

vector<string> restoreIpAddresses(string s) {
    helper(s, 0, "");
    return ans;
}
	
