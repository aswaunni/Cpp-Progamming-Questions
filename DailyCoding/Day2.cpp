/*
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> prod(n);
    
    int temp = 1;
    for (int i = 0; i < n; i++) {
        prod[i] = temp;
        temp *= v[i];
    }
    
    temp = 1;
    for (int i = n-1; i >= 0; i--) {
        prod[i] *= temp;
        temp *= v[i];
    }
    
    for (int i = 0; i < n; i++)
        cout << prod[i] << " ";
    cout << "\n";

    return 0;
}
