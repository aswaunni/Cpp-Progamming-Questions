/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"

Example 2:
Input: num = "10200", k = 1
Output: "200"

Example 3:
Input: num = "10", k = 2
Output: "0"
*/

string removeKdigits(string num, int k) {
    int n = num.size();
    stack<char> s;

    for (int i = 0; i < n; i++) {
        while (k && !s.empty() && num[i] < s.top()) {
            k--;
            s.pop();
        }
        
        if (!(s.empty() && num[i] == '0'))
            s.push(num[i]);
    }
    
    while (k && !s.empty()) {
        k--;
        s.pop();
    }
    
    if (s.empty()) return "0";
    while (!s.empty()) {
        num[n - 1] = s.top();
        s.pop(), n--;
    }
    return num.substr(n);
}
