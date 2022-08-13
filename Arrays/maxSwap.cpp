/*
You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

 

Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.
*/

int maximumSwap(int num) {
    string s = to_string(num);
    int n = s.length();
    
    vector<int> v(10, -1);
    
    for (int i = 0; i < n; i++)
        v[s[i] - '0'] = i;
    
    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';
        for (int j = 9; j > x; j--) {
            if (v[j] > i) {
                swap(s[i],s[v[j]]);
                return stoi(s);
            }
        }
    }
    
    return stoi(s);
}
