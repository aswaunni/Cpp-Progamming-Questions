/*
his problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/

#include <bits/stdc++.h>

using namespace std;

int segregate(vector<int>& v)
{
    int j = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0) {
            swap(v[i], v[j]);
            j++;
        }
    }
    return j;
}

int findMissing(vector<int>& v, int n)
{
    for (int i = 0; i < n; i++) {
        if (v[i] > 0)
            return (i+1);
    }
    return (n+1);
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int j = segregate(v);
    
    for (int i = 0; i < j; i++) {
        if ((abs(v[i]) - 1) < j && v[abs(v[i]) - 1] > 0)
            v[abs(v[i]) - 1] = -v[abs(v[i]) - 1];
    }

    cout << findMissing(v, n) << "\n";
    

    return 0;
}
