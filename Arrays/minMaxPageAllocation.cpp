/*
n - number of pages in n different books(ascending order)
m - number of students
All the books have to be divided among m students consecutively. Allocate the pages in such a way that the maximum pages allocated to a student is minimum.
*/


#include <bits/stdc++.h>

using namespace std;

bool isFeasible(vector<int> v, int value, int m) {
    int j = 0;
    for(int i = 0; i < m; i++) {
        int x = 0;
        while ((x+v[j]) <= value && j < v.size())
            x += v[j++];
    }
    return (j == v.size());
}

int pageAllocation(vector<int> v, int m) {
    if (v.size() < m)
        return -1;
    int l = 0, r = accumulate(v.begin(), v.end(), 0);
    int ans = INT_MAX;
    
    while (l <= r) {
        int mid = (l+r)/2;
        if (isFeasible(v, mid, m)) {
            r = mid-1;
            ans = min(ans, mid);
        } else {
            l = mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {12, 34, 67, 90, 114};
    
    cout << pageAllocation(v, 3);

    return 0;
}
