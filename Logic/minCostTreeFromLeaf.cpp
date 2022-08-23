/*
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

 

Example 1:


Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
Example 2:


Input: arr = [4,11]
Output: 44
*/

int mctFromLeafValues(vector<int>& arr) {
    vector<int> st;
    st.push_back(INT_MAX);
    int ans = 0;
    
    for (auto& a : arr) {
        while (st.back() <= a) {
            int x = st.back();
            st.pop_back();
            ans += x * min(a, st.back());
        }
        
        st.push_back(a);
    }
    
    for (int i = 2; i < st.size(); i++) 
        ans += st[i]*st[i-1];
    
    return ans;
}

// DP

int solve(vector<int>& arr, vector<vector<int>>& dp, int s, int e) {
    
    if (s == e)
        return dp[s][e] = 0;
    
    if (dp[s][e] != -1)
        return dp[s][e];
    
    int ans = INT_MAX;
    
    for (int i = s; i < e; i++) {
        int l = solve(arr, dp, s, i);
        int r = solve(arr, dp, i+1, e);
        
        int x = l + r + (*max_element(arr.begin()+s,arr.begin()+i+1))*(*max_element(arr.begin()+i+1,arr.begin()+e+1));
        
        ans = min(ans, x);
    }
    return dp[s][e] = ans;
}

int mctFromLeafValues(vector<int>& arr) {
    vector<vector<int>> dp(50, vector<int>(50, -1));
    return solve(arr, dp, 0, arr.size()-1);
}
