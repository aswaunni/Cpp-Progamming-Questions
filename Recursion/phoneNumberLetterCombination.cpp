/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
*/

vector<string> ans;
vector<string> v = {"", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"};

void helper(string d, int i, string& s) {
    if (i == d.size()) {
        ans.push_back(s);
        return;
    }
    
    for (auto& c : v[d[i] - '0']) {
        s.push_back(c);
        helper(d, i+1, s);
        s.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if (digits == "")
        return ans;
    string s = "";
    helper(digits, 0, s);
    return ans;
}
