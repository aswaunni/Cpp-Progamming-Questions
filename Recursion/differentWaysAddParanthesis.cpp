/*
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

 

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/

class Solution {
public:
    unordered_map<string, vector<int>> dp;
    
    vector<int> diffWaysToCompute(string expr) {
        vector<int> ans;
        
        if (dp.count(expr))
            return dp[expr];
        
        for (int i = 0; i < expr.length(); i++) {
            char c = expr[i];
            if (c == '+' || c == '-' || c == '*') {
                
                vector<int> ans1 = diffWaysToCompute(expr.substr(0, i));
                vector<int> ans2 = diffWaysToCompute(expr.substr(i+1));
                
                for (int n1 : ans1) {
                    for (int n2 : ans2) {
                        if (c == '+')
                            ans.push_back(n1 + n2);
                        else if (c == '-')
                            ans.push_back(n1 - n2);
                        else
                            ans.push_back(n1 * n2);
                    }
                }
            }
        }
        
        if (ans.empty())
            ans.push_back(atoi(expr.c_str()));
        
        return dp[expr] = ans;
    }
};
