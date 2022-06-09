/*
QUICK SORT

Time Complexity:
  Best case: O(nlogn) (Pivot in middle)
  Worst case: O(n^2) (Pivot at end)
*/

#include <bits/stdc++.h>

using namespace std;

int partition(int l, int r, vector<int>& arr) {
    int i = l-1, j = l;
    while (j < r) {
        if (arr[j] < arr[r]) {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quickSort(int l, int r, vector<int>& arr) {
    if (l < r) {
        int piv = partition(l, r, arr);
        quickSort(l, piv-1, arr);
        quickSort(piv+1, r, arr);
    }
}
   
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    quickSort(0, n-1, arr);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
