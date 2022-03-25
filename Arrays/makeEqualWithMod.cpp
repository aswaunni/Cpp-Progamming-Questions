/*
You are given an array of n non-negative integers a1,a2,…,an. You can make the following operation: choose an integer x≥2 and replace each number of the array by the remainder when dividing that number by x, that is, for all 1≤i≤n set ai to aimodx.

Determine if it is possible to make all the elements of the array equal by applying the operation zero or more times.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. Description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤105) — the length of the array.

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤109) where ai is the i-th element of the array.

The sum of n for all test cases is at most 2⋅105.

Output
For each test case, print a line with YES if you can make all elements of the list equal by applying the operation. Otherwise, print NO.

You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as a positive answer).

Example
inputCopy
4
4
2 5 6 8
3
1 1 1
5
4 1 7 0 8
4
5 9 17 5
outputCopy
YES
YES
NO
YES
*/

void solve() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    bool bad = false;
    for (int i = 0; i < n; i++) cin >> v[i];
    
    sort(v.begin(), v.end());
    
    for (int i = 1; i < n; i++) {
        if (v[i-1] + 1 == v[i]) {
            bad = true;
            break;
        }
    }
    
    if (bad && count(v.begin(), v.end(), 1))
        cout << "NO\n";
    else
        cout << "YES\n";
}
