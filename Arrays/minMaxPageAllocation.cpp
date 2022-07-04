/*
n - number of pages in n different books(ascending order)
m - number of students
All the books have to be divided among m students consecutively. Allocate the pages in such a way that the maximum pages allocated to a student is minimum.
*/


#include <bits/stdc++.h>

using namespace std;

bool isFeasible(vector<int> v, int value, int m) {
    int sum = 0, count = 1;
    for(int i = 0; i < v.size(); i++) {
        if(sum+v[i] > value) {
            count++;
            sum = v[i];
            if (count > m)
                return false;
        } else
            sum += v[i];
    }
    return true;
}

int pageAllocation(vector<int> v, int m) {
    if (v.size() < m)
        return -1;
    int l = 0, r = accumulate(v.begin(), v.end(), 0);
    
    while (l < r) {
        int mid = (l+r)/2;
        if (isFeasible(v, mid, m))
            r = mid;
        else
            l = mid+1;
    }
    return l;
}

int main()
{
    vector<int> v = {12, 34, 67, 90};
    
    cout << pageAllocation(v, 3);

    return 0;
}
