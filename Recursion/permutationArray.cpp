/*
Find all permutations of given array
*/

// Without duplicates

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

void perm(vector<int> arr, int idx) {
    if (idx == arr.size()) {
        ans.push_back(arr);
        return;
    }

    for (int i = idx; i < arr.size(); i++) {
        swap(arr[i], arr[idx]);
        perm(arr, idx+1);
    }
}

// Using STL

void perm(vector<int> arr, int idx) {
    sort(arr.begin(), arr.end());

    do {
        ans.push_back(arr);
    } while (next_permutation(arr.begin(), arr.end()));
}
----------------------
  //With Duplicates
  
  vector<vector<int>> ans;

void perm(vector<int> arr, int idx) {
    if (idx == arr.size()) {
        ans.push_back(arr);
        return;
    }

    for (int i = idx; i < arr.size(); i++) {
        if (i != idx && arr[i] == arr[idx]) // check extra
            continue;
        swap(arr[i], arr[idx]);
        perm(arr, idx+1);
    }
}
