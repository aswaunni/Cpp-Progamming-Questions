/*
Remove duplicate characters from the string
*/

#include <bits/stdc++.h>

using namespace std;

string dup(string s, int i) {
    if (i == s.length())
        return "";
    if (i == 0 || s[i] != s[i-1])
        return s[i] + dup(s, i+1);
    return dup(s, i+1);
}

int main()
{

    string s;
    cout << "enter s:";
    cin >> s;
    
    cout << dup(s, 0);
}
