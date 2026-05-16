class Solution {
public:
    unordered_map<int, int> dp;
    int coinChange(vector<int>& coins, int amount) {
        return dfs(coins, amount);
    }

    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (dp.count(amount)) return dp[amount];

        int res = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int count = dfs(coins, amount - coins[i]);
            dp[amount - coins[i]] = count;
            if (count == -1) continue;
            else res = min(res, count + 1);
        }

        return res == INT_MAX ? -1 : res;
    }
};
