/*
Find ll permutation of given string.
*/

#include <bits/stdc++.h>

using namespace std;

void func(string s, string ans) {
    if (0 == s.length()) {
        cout << ans << endl;
        return;
    }

     for (int i = 0; i < s.length(); i++) {
         char ch = s[i];
         string res = s.substr(0, i) + s.substr(i+1);
         func(res, ans + ch);
     }
}

int main()
{

    string s;
    cout << "enter s:";
    cin >> s;
    
    func(s, "");
}
