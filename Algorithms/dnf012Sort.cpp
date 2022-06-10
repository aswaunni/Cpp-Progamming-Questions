/*
DUTCH NATIONAL FLAG (DNF) / 012 SORT

Time Complexity : O(n)

low -0s start
mid - unknown region starts
high - 2s start
*/

#include <bits/stdc++.h>

using namespace std;

void dnfSort(vector<int>& arr, int n) {
    int low = 0, mid = 0, high = n-1;

    while(mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low++], arr[mid++]);
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[high--], arr[mid++]);
        }
    }

}
   
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    dnfSort(arr, n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
