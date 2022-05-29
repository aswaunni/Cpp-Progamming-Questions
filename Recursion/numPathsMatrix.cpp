/*
The problem is to count all the possible paths from top left to bottom right of a MxN matrix with the constraints that from each cell you can either move to right or down.

Example 1:

Input:
M = 3 and N = 3
Output: 6
*/

#include <bits/stdc++.h>

using namespace std;

int func(int i, int j, int n) {
    if (i == n-1 && j == n-1)
        return 1;
    if (i >= n || j >= n)
        return 0;
        
    return (func(i, j+1, n) + func(i+1, j, n));
}

int main()
{

    int n;
    cout << "enter n:";
    cin >> n;
    
    cout << func(0, 0, n);
}
