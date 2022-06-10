/*
Count the inversions ie. a[i] > a[j] where i < j.

Using merge sort. 
Time Complexity : O(nlog(n))
*/


#include <bits/stdc++.h>

using namespace std;


long long merge(vector<int>& arr, int l, int m, int r) {
    long long inv = 0;
    int n1 = m-l+1, n2 = r-m;
    vector<int> a(n1), b(n2);

    for(int i = 0; i < n1; i++) a[i] = arr[l+i];
    for(int i = 0; i < n2; i++) b[i] = arr[m+1+i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k++] = a[i++];
        } else {
            inv += (n1-i);
            arr[k++] = b[j++];
        }
    }

    while (i < n1)
        arr[k++] = a[i++];

    while (j < n2)
        arr[k++] = b[j++];

    return inv;

}

long long mergeSort(vector<int>& arr, int l, int r) {
    long long inv = 0;
    if (l < r) {   
        int m = l + (r-l)/2;
        inv += mergeSort(arr, l, m);
        inv += mergeSort(arr, m+1, r);

        inv += merge(arr, l, m, r);
    }
    return inv;
}
   
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

   

 //   for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl <<  mergeSort(arr, 0, n-1) << endl;
}
