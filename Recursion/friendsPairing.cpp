/*
Find number of ways in which n friends can be paired up or can stay single
*/

#include <bits/stdc++.h>

using namespace std;

int func(int n) {
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    return (func(n-1) + (n-1)*func(n-2));
}

int main()
{

    int n;
    cout << "enter n:";
    cin >> n;
    
    cout << func(n);
}
