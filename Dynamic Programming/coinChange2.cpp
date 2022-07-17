/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4

Example 2:
Input: amount = 3, coins = [2]
Output: 0

Example 3:
Input: amount = 10, coins = [10]
Output: 1
*/

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount+1, 0);
    dp[0] = 1;
    
    for (auto& c : coins) {
        for (int i = c; i <= amount; i++)
            dp[i] += dp[i - c];
    }
    return dp[amount];
}
