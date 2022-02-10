/*
K Distinct Array Problem Code: DISTK

An array is said to be good if all its elements are distinct, i.e. no two elements of the array are equal to each other.

You are given a positive integer N and an integer K such that N≤K≤(N+12).

Construct an array A of length N that satisfies the following conditions

A has exactly K good (contiguous) subarrays, and
Every element of A is an integer from 1 to N (both inclusive).
If there are multiple such arrays, you can print any of them.

Note: It can be shown that for all inputs satisfying the given constraints, there is always a valid solution.

Input Format
The first line contains an integer T, the number of testcases. The description of the T testcases follow.
Each testcase consists of a single line with two space separated integers, N and K respectively.
Output Format
For each testcase print N space separated integers, the elements of the constructed array.
If there are multiple outputs, you can print any of them.
Your output will be considered correct only if the following conditions are satisfied,
Every element of the array is between 1 and N, and
The array has exactly K good subarrays
Constraints
1≤T≤105
1≤N≤105
N≤K≤(N+12)
Sum of N over all testcases is atmost 3⋅105.
Sample Input 1 
3
5 5
5 15
5 7
Sample Output 1 
1 1 1 1 1
1 2 3 4 5
1 2 2 1 1
*/

#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    long long count = 0;
    for (long long i = 1; i <= n; ++i)
    {
        long long f = (i * (i + 1)) / 2;

        if ((k - f) < (n - i))
            break;
        count++;
        cout << count << " ";
    }

    k -= (count * (count + 1)) / 2;
    if (count < n)
        k -= (n - count);

    int itr = count;
    while (itr < n) {
        cout << count - k << " ";
        ++itr;
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
