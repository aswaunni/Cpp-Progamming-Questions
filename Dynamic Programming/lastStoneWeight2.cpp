/*
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the smallest possible weight of the left stone. If there are no stones left, return 0.

 

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.
Example 2:

Input: stones = [31,26,33,21,40]
Output: 5
*/

int lastStoneWeightII(vector<int>& nums) {
    //answer = S1-S2
    //where S1 is sum of some of the numbers and S2 is sum of rest of numbers
    //also note that S1+S2 = SUM (sum of all numbers)
    //S1 >= S2 beacuse negative answer is not possible
    //now we have to minimise answer
    //answer = SUM - 2*S2 (Just substituting S1 by SUM-S2)
    //To minimise answer S2 has to be maximum
    //Now, max value of S2 is SUM/2 (bigger than this and answer would be negative which is not possible)
    //so the question reduces to find closest sum (sum of numbers) to (SUM/2)
    //now this could be understood as subset sum problem or 0/1 knapsack problem
    
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    int sum = total/2;
    
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j >= nums[i-1])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - nums[i-1]] + nums[i-1]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return total - 2*dp[n][sum];
}

// OR

int lastStoneWeightII(vector<int>& stones) {
    unordered_set<int> s = {0};
    
    int ans = 100;
    for (int i = 0; i < stones.size(); i++) {
        unordered_set<int> t = s;
        s = {};
        for (auto&a : t) {
            s.insert(a + stones[i]);
            s.insert(a - stones[i]);
        }
    }
    
    for (auto& a : s)
        ans = min(ans, abs(a));
    return ans;
}
