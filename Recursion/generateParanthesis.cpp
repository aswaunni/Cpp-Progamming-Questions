/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

// HINT
We need to interpret the meanings of constraints. First, the first character should be “(“. 
Second, at each step, you can either print “(“ or “)”, but print “)” only when there are more “(“s than “)”s. 
Stop printing out “(“ when the number of “(“ s hit n. The first actually merges into the second condition.

*/

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    backtrack(ans, "", 0, 0, n);
    return ans;
}

void backtrack(vector<string>& ans, string cur, int open, int close, int n) {
    if (cur.length() == 2*n) {
        ans.push_back(cur);
        return;
    }
    
    if (open < n) 
        backtrack(ans, cur+'(', open+1, close, n);
    
    if (open > close)
        backtrack(ans, cur+')', open, close+1, n);
}
