/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
*/

int nthUglyNumber(int n) {
    vector<int> ans(n, 1);
    int i = 0, j = 0, k = 0;
    
    for (int itr = 1; itr < n; ++itr) {
        ans[itr] = min({ans[i] * 2, ans[j] * 3, ans[k] * 5}); // checking the minimum of next multiples of 2, 3, 5
        if (ans[itr] == ans[i] * 2)
            ++i;
        if (ans[itr] == ans[j] * 3)
            ++j;
        if (ans[itr] == ans[k] * 5)
            ++k;
    }
    return ans[n-1];
}
