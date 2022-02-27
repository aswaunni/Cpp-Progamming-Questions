/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
*/

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        for (auto& a : coins) {
            if (i >= a)
                dp[i] = min(dp[i], dp[i - a] + 1);
        }
    }
    return (dp[amount] > amount ? -1 : dp[amount]);
}

// OR

int minCoins(int coins[], int n, int v) 
{ 
    vector<int> dp(v+1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= v; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }
    return (dp[v] == INT_MAX ? -1 : dp[v]);
} 
