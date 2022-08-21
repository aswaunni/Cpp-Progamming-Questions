/*
We call a positive integer special if all of its digits are distinct.

Given a positive integer n, return the number of special integers that belong to the interval [1, n].

 

Example 1:

Input: n = 20
Output: 19
Explanation: All the integers from 1 to 20, except 11, are special. Thus, there are 19 special integers.
Example 2:

Input: n = 5
Output: 5
Explanation: All the integers from 1 to 5 are special.
Example 3:

Input: n = 135
Output: 110
Explanation: There are 110 integers from 1 to 135 that are special.
Some of the integers that are not special are: 22, 114, and 131.
*/

int countSpecialNumbers(int num) {
    string s = to_string(num);
    int n = s.length();
    
    int ans = 0;
    
    for (int i = 1; i < n; i++) {
        int x = 9, mul = 1;
        for (int j = 0; j < i-1; j++) {
            mul *= x;
            x--;
        }
        ans += mul*9;
    }
    
    vector<bool> done(10, false);
    for (int i = 0; i < n; i++) {
        int smaller = 0;
        int si = s[i] - '0';
        for (int j = 0; j < si; j++) {
            if (!done[j])
                smaller++;
        }
        
        if (i == 0)
            smaller--;
        
        int rem = 10 - i - 1, mul = 1;
        for (int j = i+1; j < n; j++) {
            mul *= rem;
            rem--;
        }
        
        ans += smaller*mul;
        
        if (done[si])
            return ans;
        else
            done[si] = true;
    }
    return ans+1;
}
