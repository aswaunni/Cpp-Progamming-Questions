/*
Find all substring of given string
*/

#include <bits/stdc++.h>

using namespace std;

void sub(string s, int i, string ans) {
    if (i == s.length()) {
        cout << ans << endl;
        return;
    }
    sub(s, i+1, ans);
    sub(s, i+1, ans+s[i]);
}

int main()
{

    string s;
    cout << "enter s:";
    cin >> s;
    
    sub(s, 0, "");
}
