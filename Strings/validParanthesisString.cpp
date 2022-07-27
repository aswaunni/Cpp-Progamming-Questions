/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
 
*/

bool checkValidString(string s) {
    int cmx = 0, cmn = 0; // count max and minimum number of (
    
    for (auto& c : s) {
        if (c == '(') {
            cmx++;
            cmn++;
        } else if (c == ')') {
            cmx--;
            cmn--;
        } else {
            cmx++;
            cmn--;
        }
        if (cmx < 0)
            return false;
        cmn = max(0, cmn);
    }
    return (cmn == 0);
}
