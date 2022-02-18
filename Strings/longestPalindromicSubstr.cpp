/*
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
*/

string longestPalindrome(string s) {
    if (s.length() < 1) return "";
    
    string str;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        str.push_back('#');
        str.push_back(s[i]);
    }
    str.push_back('#');
    
    int center = 0, radius = 0, mxRad = 0, mxCtr = 0;
    int n2 = str.length();
    
    while (center < n2) {
        radius = 0;
        while ((center - (radius + 1)) >= 0 && (center + (radius + 1)) < n2 && str[center - (radius + 1)] == str[center + (radius + 1)])
            radius++;
        
        if (radius > mxRad) {
            mxRad = max(mxRad, radius);
            mxCtr = center;
        }
        center++;
    }
    return s.substr((mxCtr - mxRad)/2, mxRad);
}

// OR -> expandAroundCenter

int expandAroundCenter(int l, int r, string s) {
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
        l--;
        r++;
    }
    return r-l-1;
}

string longestPalindrome(string s) {
    if (s.length() < 1) return "";
    
    int start = 0, lMax = 0;
    for (int i = 0; i < s.length(); i++) {
        int l = max(expandAroundCenter(i, i, s), expandAroundCenter(i, i+1, s));
        if (l > lMax) {
           lMax = l;
           start = i - (l-1)/2;
        }
    }
    return s.substr(start, lMax);
}

// OR -> DP

string longestPalindrome(string s) {
    
    int n=s.length();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int maxLen=1;
    int start=0;
    
    for(int i=0;i<n-1;i++){
        dp[i][i]=1;
        dp[i][i+1]=(s[i]==s[i+1]);
        if(dp[i][i+1] and maxLen==1){
            maxLen=2;
            start=i;
        }
    }

    dp[n-1][n-1]=1;
    for(int k=2;k<n;k++){ 
            int i=0,j=k;
            while(i<n-k and j<n){
                    dp[i][j]=(s[i]==s[j] and dp[i+1][j-1]);
                    int len=j-i+1;
                    if(dp[i][j] and len>maxLen){
                        maxLen=len;
                        start=i;
                    }
                i++,j++;
            }   
        }
    
    return s.substr(start,maxLen);
    
}
