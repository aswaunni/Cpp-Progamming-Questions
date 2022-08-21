/*
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.

 

Example 1:

Input: pattern = "IIIDIDDD"
Output: "123549876"
Explanation:
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.
Example 2:

Input: pattern = "DDD"
Output: "4321"
Explanation:
Some possible values of num are "9876", "7321", and "8742".
It can be proven that "4321" is the smallest possible num that meets the conditions.
*/

class Solution {
public:
    string res = "";
    bool helper(int itr, int start, string ans, string pattern, vector<bool>& vis) {
        if (start < 1 || start > 9 || vis[start])
            return false;
        
        if (ans.length() == pattern.length()+1) {
            res = ans;
            return true;
        }
        
        vis[start] = true;
        if (pattern[itr] == 'I') {
            for (int i = start+1; i <= 9; i++) {
                if (helper(itr+1, i, ans+to_string(i), pattern, vis))
                    return true;
            }
        } else {
            for (int i = start-1; i >= 1; i--) {
                if (helper(itr+1, i, ans+to_string(i), pattern, vis))
                    return true;
            }
        }
        vis[start] = false;
        return false;
    }
    string smallestNumber(string pattern) {
        
        vector<bool> vis(10, false);
        for (int i = 1; i <= 9; i++) {
            if (helper(0, i, to_string(i), pattern, vis)) {
                return res;
            }
        }
        return res;
    }
};
