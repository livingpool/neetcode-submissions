class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);

        for (int i = 0; i < n; i++) {
            int s = dp.size();
            dp.push_back(dp[s-1] + dp[s-2]);
        }

        return dp[dp.size() - 1];
    }
};
