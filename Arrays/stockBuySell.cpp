/*
The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.
Note: There may be multiple possible solutions. Return any one of them. Any correct solution will result in an output of 1, whereas wrong solutions will result in an output of 0.

Example 1:

Input:
N = 7
A[] = {100,180,260,310,40,535,695}
Output:
1
Explanation:
One possible solution is (0 3) (4 6)
We can buy stock on day 0,
and sell it on 3rd day, which will 
give us maximum profit. Now, we buy 
stock on day 4 and sell it on day 6.

Answer: Valley Peak approach
*/

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int mn = INT_MAX;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        mn = min(mn, prices[i]);
        ans = max(ans, prices[i] - mn);
    }
    return ans;
}

//OR

vector<vector<int> > stockBuySell(vector<int> A, int n)
{
    vector<vector<int>> ans;
    
    int i = 0;
    while (A[i+1] <= A[i] && i+1 < n) i++;
    
    int j = i;
    while (j+1 < n) {
        if (A[j+1] < A[j]) {
            ans.push_back({i, j});
            i = j+1;
        }
        j++;
    }
    if (j > i)
        ans.push_back({i, j});
        
    return ans;
}

