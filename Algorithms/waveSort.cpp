/*
WAVE SORT

Time Complexity : O(n/2)
*/

#include <bits/stdc++.h>

using namespace std;

void waveSort(vector<int>& arr, int n) {
    
    for (int i = 1; i < n; i+=2) {
        if (arr[i] > arr[i-1])
            swap(arr[i], arr[i-1]);

        if (arr[i] > arr[i+1] && i < (n-1))
            swap(arr[i], arr[i+1]);
    }
}
   
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    waveSort(arr, n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
