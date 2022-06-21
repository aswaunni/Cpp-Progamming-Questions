/*
Given an array of 0s and 1s, we may change upto K values from 0 to 1.
Return the length of longest contiguous subarray of 1s.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v{1, 1, 1,0,0,0,1,1,1,1,0};
    int k = 2;
    
    int i = 0;
    int cnt = 0, ans = 0;
    
    for (int j = 0; j < v.size(); j++) {
        if (v[j] == 0)
            cnt++;
        while (cnt > k) {
            if (v[i] == 0) {
                cnt--;
            }
            i++;
        }
        ans = max(ans, j-i+1);
    }
    cout << ans;

    return 0;
}
