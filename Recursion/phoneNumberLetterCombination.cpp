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

string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void func(string s, string ans, int i) {
    if (i == s.length()) {
        cout << ans << endl;
        return;
    }

    int k = s[i] - '0';
    for (int j = 0; j < keypad[k].length(); j++)
        func(s, ans+keypad[k][j], i+1);
}

int main()
{

    string s;
    cout << "enter s:";
    cin >> s;
    
    func(s, "", 0);
}
