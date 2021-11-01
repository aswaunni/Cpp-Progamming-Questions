/*
Good morning! Here's your coding interview problem for today.

This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        if (m.count(k-v[i]) > 0) {
            cout << v[i] << " " << k-v[i] << "\n";
            break;
        }
        m[v[i]]++;
    }
    return 0;
}
