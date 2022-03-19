/*
You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.

Return the rearranged number with minimal value.

Note that the sign of the number does not change after rearranging the digits.

 

Example 1:
Input: num = 310
Output: 103

Example 2:
Input: num = -7605
Output: -7650
*/

long long smallestNumber(long long num) {
    auto s = to_string(abs(num));

    sort(s.begin(), s.end(), [&] (int a, int b) {
        return (num < 0 ? a > b : a < b);
    });
    if (num > 0)
        swap(s[0], s[upper_bound(s.begin(), s.end(), '0') - s.begin()]);
    
    return (stoll(s) * (num < 0 ? -1 : 1));
}
