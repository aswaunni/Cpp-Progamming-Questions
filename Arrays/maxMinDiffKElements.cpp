/*
Given an array with n elements that are n positions on a line, find k elemets such that the minimum distance between 2 elements is the maxium possible.
*/


#include <bits/stdc++.h>

using namespace std;

bool isFeasible(int mid, vector<int> v, int n, int k) {
    int pos = v[0], elements = 1;
    
    for(int i = 0; i < n; i++) {
        if (v[i] - pos >= mid) {
            pos = v[i];
            elements++;
            if (elements == k)
                return true;
        }
    }
    return false;
}

int maxMinDistance(vector<int> v, int k) {
    int n = v.size();
    
    int l = 1, r = v[n-1];
    int ans = -1;
    
    while (l < r) {
        int mid = (l+r)/2;
        if (isFeasible(mid, v, n, k)) {
            ans = max(ans, mid);
            l = mid+1;
        } else 
            r = mid;
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 2, 5, 7, 11, 12};
    cout << maxMinDistance(v, 3);
    return 0;
}
