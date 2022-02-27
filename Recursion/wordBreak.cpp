/*
Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.

Note: From the dictionary B each word can be taken any number of times and in any order.
Example 1:

Input:
n = 12
B = { "i", "like", "sam",
"sung", "samsung", "mobile",
"ice","cream", "icecream",
"man", "go", "mango" }
A = "ilike"
Output:
1
Explanation:
The string can be segmented as "i like".

Example 2:

Input:
n = 12
B = { "i", "like", "sam",
"sung", "samsung", "mobile",
"ice","cream", "icecream", 
"man", "go", "mango" }
A = "ilikesamsung"
Output:
1
Explanation:
The string can be segmented as 
"i like samsung" or "i like sam sung".
*/

int wordBreak(string A, vector<string> &B) {
    if (A.length() == 0)
        return true;
    
    for (int i = 1; i <= A.length(); i++) {
        if (find(B.begin(), B.end(), A.substr(0, i)) != B.end() && wordBreak(A.substr(i), B))
            return true;
    }
    return false;
}
