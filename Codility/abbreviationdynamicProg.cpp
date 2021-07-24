/*
You can perform the following operations on the string, a:

1. Capitalize zero or more of a's lowercase letters.
2. Delete all of the remaining lowercase letters in a.
Given two strings, a and b, determine if it's possible to make a equal to b as described. If so, print YES on a new line. Otherwise, print NO.

For example, given a = AbcDE and b = ABDE, in a we can convert b and delete c to match b. 

Function Description

Complete the function  in the editor below. It must return either YES or NO.

abbreviation has the following parameter(s):

a: the string to modify
b: the string to match
Input Format

- The first line of each query contains a single string, a.
- The second line of each query contains a single string, b.

Constraints

String a consists only of uppercase and lowercase English letters, ascii[A-Za-z].
String b consists only of uppercase English letters, ascii[A-Z].
Output Format

For each query, print YES on a new line if it's possible to make string a equal to string b. Otherwise, print NO.

Sample Input

1
daBcd
ABC
Sample Output

YES
*/

bool isUpper(char c) {
    return (c >= 'A' && c <= 'Z');
}

char toUpper(char c) {
    if (isUpper(c))
        return c;
    return (c - ('a' - 'A'));
}

string abbreviation(string a, string b) {
    bool dp[1001][1001] = {false};
    
    dp[0][0] = true;
    
    for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j <= b.length(); j++) {
            if (dp[i][j]) {
                if (j < b.length() && (toUpper(a[i]) == b[j]))
                    dp[i+1][j+1] = true;
                if (!isUpper(a[i]))
                    dp[i+1][j] = true;
            }
        }
    }
    return (dp[a.length()][b.length()] ? "YES" : "NO");
}
