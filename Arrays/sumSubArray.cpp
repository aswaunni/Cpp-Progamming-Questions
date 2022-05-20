/*
Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter n :";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
    int sum;
    cout << "Enter sum : ";
    cin >> sum;

    int s = 0, e = 0, add = 0;
    for (int i = 0; i < n; i++) {
        add += arr[i];
        e = i;
        while (add > sum && s < i) {
            add -= arr[s];
            s++;
        }
        if (add == sum) {
            cout << s+1 << ", " << e+1;
            break;
        }
    }
    return 0;
}
