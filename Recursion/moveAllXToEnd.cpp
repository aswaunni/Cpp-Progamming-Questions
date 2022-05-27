/*
Move all 'x'in string to end of String
*/

#include <bits/stdc++.h>

using namespace std;

string movex(string s, int i) {
    if (i == s.length())
        return "";
    if (s[i] != 'x')
        return s[i] + movex(s, i+1);
    return movex(s, i+1) + s[i];
}

int main()
{

    string s;
    cout << "enter s:";
    cin >> s;
    
    cout << movex(s, 0);
}
