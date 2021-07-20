/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> &A) {
    int n = A.size();
    for (int i = 0; i < n; i++)
        A[i] = A[i]*A[i];

    int i = 0, j = n-1;
    vector<int> res(n);
    int idx = n-1;

    while (i <= j) {
        if (A[i] >= A[j])
            res[idx--] = A[i++];
        else
            res[idx--] = A[j--];
    }
    return res;
}
        

int main()
{
    vector<int> arr = {-6, -3, -1, 2, 4, 5};
    
    vector<int> res = solve(arr);
    
    for (auto& a : res)
        cout << a << " ";

    return 0;
}
