class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, l = prices[0];
        for (const auto&p : prices) {
            profit = max(profit, p - l);
            if (p < l) l = p;
        }
        return profit;
    }
};
