/*
n - length of n different boards
m = painters available
A painters paints 1 unit of board in 1 unit of time and each painter will paint consecutive boards.
Find the minimum time that will be required to paint all boards.
*/


#include <bits/stdc++.h>

using namespace std;

bool isFeasible(vector<int> v, int value, int m) {
    int countPainters = 1;
    int painted = 0;
    for(int i = 0; i < v.size(); i++) {
        if (painted + v[i] > value) {
            countPainters++;
            painted = v[i];
            if (countPainters > m)
                return false;
        } else
            painted += v[i];
    }
    return true;
}

int paintBoards(vector<int> v, int m) {
    int l = 0, r = 0;
    
    for (int i = 0; i < v.size(); i++) {
        l = max(l, v[i]);
        r += v[i];
    }
    
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
    vector<int> v = {10, 20, 30, 40};
    
    cout << paintBoards(v, 2);

    return 0;
}
