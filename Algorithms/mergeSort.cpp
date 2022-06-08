/*
MERGE SORT
*/

#include <bits/stdc++.h>

using namespace std;

void merge(int l, int m, int r, vector<int>& arr) {
    int n1 = m-l+1, n2 = r-m;
    vector<int> t1(n1), t2(n2);

    for (int i = 0; i < n1; i++) t1[i] = arr[l+i];
    for (int i = 0; i < n2; i++) t2[i] = arr[m+1+i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (t1[i] <= t2[j])
            arr[k++] = t1[i++];
        else
            arr[k++] = t2[j++];
    }

    while(i < n1)
        arr[k++] = t1[i++];
    while (j < n2)
        arr[k++] = t2[j++];
}

void mergeSort(int l, int r, vector<int>& arr) {
    if (l < r) {
        int m = (l+r)/2;
        mergeSort(l, m, arr);
        mergeSort(m+1, r, arr);
        merge(l, m, r, arr);
    }
}
   
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    mergeSort(0, n-1, arr);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
