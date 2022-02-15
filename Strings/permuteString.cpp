/*
Given a string S. The task is to print all permutations of a given string.

 
 
 Example 1:
 
 Input: ABC
 Output:
 ABC ACB BAC BCA CAB CBA
 Explanation:
 Given string ABC has permutations in 6 
 forms as ABC, ACB, BAC, BCA, CAB and CBA .
 
 */
 
#include <bits/stdc++.h>

using namespace std;

void permute(string s, string temp, vector<string>& ans)
{
    if (l == r)
        ans.push_back(s);
        
    for (int i = l; i <= r; i++) {
        swap(s[i], s[l]);
        permute(s, l+1, r, ans);
        swap(s[i], s[l]);
    }
}

// OR

void permute(string s, string temp, vector<string>& ans)
{
    if (s.length() == 0) {
        ans.push_back(temp);
        return;
    }
        
    for (int i = 0; i < s.length(); i++) {
        string x = s.substr(0, i) + s.substr(i+1);
        char c = s[i];
        permute(x, temp+c, ans);
    }
}

vector<string> find_permutation(string s)
{
    vector<string> ans;
    permute(s, "", ans);
    return ans;
}


