/*
Put items from n given items wth weight and value into a knapsack of capacity W such that the value is maximum.
*/

#include <bits/stdc++.h>

using namespace std;

int func(int v[], int w[], int n, int W) {
    if (n == 0 || W == 0) {
        return 0;
    }

    if (w[n-1] > W)
        return func(v, w, n-1, W);

    return max(v[n-1] + func(v, w, n-1, W-w[n-1]), func(v, w, n-1, W));
}

int main()
{

    int n = 3;
    int w[] = {10, 20, 30};
    int v[] = {100, 50, 150};
    int W = 50;

    cout << func(v, w, 3, W);
}
