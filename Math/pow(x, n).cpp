/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/

double myPow(double x, int n) {
    // express the power n as sum od powers of 2
    double ans = 1.0;
    while (n != 0) {
        if (n%2) { // if odd number
            if (n > 0)
                ans *= x;
            else
                ans /= x;
        }
        
        x *= x;
        n /= 2;
    }
    return ans;
}
