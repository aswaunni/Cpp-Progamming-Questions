/*
Given two large numbers as strings s1 and s2. Calculate their Product.
Note: The numbers can be negative.


Example 1:

Input:
s1 = "33"
s2 = "2"
Output:
66
Example 2:

Input:
s1 = "11"
s2 = "23"
Output:
253

Your Task:

You don't need to read input or print anything. Your task is to complete the function multiplyStrings() which takes two strings s1 and s2 as input and returns their product as a string.

Note : You are not allowed to use any built-in function or convert the strings to integer.


Expected Time Complexity: O(n1* n2)
Expected Auxiliary Space: O(n1 + n2) ; where n1 and n2 are sizes of strings s1 and s2 respectively.

*/

string multiplyStrings(string s1, string s2) {
    if (s1 == "0" || s2 == "0")
        return "0";
        
    bool neg = false;
    if (s1[0] == '-' && s2[0] != '-') {
        neg = true;
        s1[0] = '0';
    } else if (s1[0] != '-' && s2[0] == '-') {
        neg = true;
        s2[0] = '0';
    } else if (s1[0] == '-' && s2[0] == '-') {
        s1[0] = '0';
        s2[0] = '0';
    }
    
    int n1 = s1.length(), n2 = s2.length();
    vector<int> v(n1+n2, 0);
    
    for (int i  = n1-1; i >= 0; i--) {
        for (int j = n2-1; j >= 0; j--) {
            v[i+j+1] += (s1[i] - '0') * (s2[j] - '0');
            v[i+j] += v[i+j+1]/10;
            v[i+j+1] %= 10;
        }
    }
    
    int i = 0;
    while (v[i] == 0 && i < v.size()) i++;
    
    string ans;
    if (neg)
        ans += '-';
        
    while (i < v.size()) ans += to_string(v[i++]);
    
    return ans;
}
