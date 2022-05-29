/*
Count the number of pats from srt to end using dice roll.
*/

#include <bits/stdc++.h>

using namespace std;

int func(int s, int e) {
    if (s == e)
        return 1;
    if (s > e)
        return 0;
    int ans = 0;
    for (int i = 1; i <= 6; i++) {
        ans += func(s, e - i);
    }
    return ans;
}

int main()
{

    int s, e;
    cout << "enter s, e:";
    cin >> s >> e;
    
    cout << func(s, e);
}
