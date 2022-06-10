/*
COUNT SORt

TimeComplexity : On(max(n, maxAi))
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> countSort(vector<int> arr, int n) {
    int k = *max_element(arr.begin(), arr.end());
    vector<int> cnt(k+1, 0);

    for (int i = 0; i < n; i++)
        cnt[arr[i]]++;

    for (int i = 1; i <= k; i++)
        cnt[i] += cnt[i-1];

    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--)
        ans[--cnt[arr[i]]] = arr[i];
    return ans;
}
   
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    arr = countSort(arr, n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
