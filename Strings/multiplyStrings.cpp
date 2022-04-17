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

string multiplyStrings(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
        return "0";
        
    bool neg = false;
    if (num1[0] == '-' && num2[0] != '-') {
        neg = true;
        num1[0] = '0';
    } else if (num1[0] != '-' && num2[0] == '-') {
        neg = true;
        num2[0] = '0';
    } else if (num1[0] == '-' && num2[0] == '-') {
        num1[0] = '0';
        num2[0] = '0';
    }
    
    int n = num1.size() + num2.size();
    string ans(n, '0');
    
    for (int i = num1.size()-1; i >= 0; --i) {
        int d1 = num1[i] - '0';
        for (int j = num2.size()-1; j >= 0; --j) {
            int d2 = num2[j] - '0';
            int zeroes = i + j;
            int pdt = d1 * d2 + (ans[i+j+1] - '0');
            
            ans[i+j+1] = pdt%10 + '0';
            ans[i+j] += pdt/10;
        }
    }
    
    while (ans.front() == '0')
        ans.erase(ans.begin());
    
    return ans;

    if (neg)
        ans += '-';
    return ans;
}
