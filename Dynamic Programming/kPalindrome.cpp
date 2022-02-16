/*
A string is k palindrome if it can be transformed into a palindrome on removing at most k characters from it. Your task is to complete the function is_k_palin which takes two arguments a string str and a number N . Your function should return true if the string is k palindrome else it should return false.

Input:
The first line of input is an integer T denoting the number of test cases . Then T test cases follow . Each test case  contains a string str and an integer N separated by space.  

Output:
The output will be 1 if the string is  k palindrome else 0 .

Constraints:
1<=T<=100
1<=length of str<=100
1<=N<=20

Example:
Input
2
abcdecba 1
acdcb  1
Output
1
0
*/

int lcs(int x, int y, string s1, string s2) //  longest common subsequence
{
    vector<vector<int>> dp(x+1, vector<int>(y+1, 0));
    
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[x][y];
}

bool is_k_palin(string s,int k)
{
    int n = s.length();
    string s2(s);
    reverse(s2.begin(), s2.end());
    return (n - lcs(n, n, s, s2) <= k ? true : false);
}
