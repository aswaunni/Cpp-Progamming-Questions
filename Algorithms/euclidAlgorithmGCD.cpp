/*
-----------------------------
EUCLIDS ALGORITHM TO FIND GCD
-----------------------------

The algorithm is based on the below facts. 

If we subtract a smaller number from a larger (we reduce a larger number), GCD doesn’t change. So if we keep subtracting repeatedly the larger of two, we end up with GCD.
Now instead of subtraction, if we divide the smaller number, the algorithm stops when we find remainder 0.

*/

int gcd(int a, int b)
{
    while (b) {
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}
