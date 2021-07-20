/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int> &A) {
    int n = A.size();
    int sum = A[n-1] + 1;
    int carry = sum/10;
    A[n-1] = sum%10;

    for (int i = n-2; i >=0 ; i--) {
        sum = A[i] + carry;
        A[i] = sum%10;
        carry = sum/10;
    }

    vector<int> res;
    bool flag = false;

    if (carry) {
        res.push_back(carry);
        flag = true;
    }

    for (int i = 0; i < n; i++) {
        if (A[i] != 0)
            flag = true;
        if (flag)
            res.push_back(A[i]);
    }
    return res;
}
        

int main()
{
    vector<int> arr = {0, 1, 2, 3};
    
    vector<int> res = plusOne(arr);
    
    for (auto& a : res)
        cout << a;

    return 0;
}
