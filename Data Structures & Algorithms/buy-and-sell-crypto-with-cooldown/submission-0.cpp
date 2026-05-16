class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> rest(n);
        vector<int> buy(n);
        vector<int> sell(n);

        rest[0] = 0;
        buy[0] = -prices[0];
        sell[0] = INT_MIN;

        for (int i = 1; i < n; i++) {
            rest[i] = max(rest[i-1], sell[i-1]);
            buy[i] = max(buy[i-1], rest[i-1] - prices[i]);
            sell[i] = buy[i-1] + prices[i];
        }   
        return max(rest[n-1], sell[n-1]);
    }
};
