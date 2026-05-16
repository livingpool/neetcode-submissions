class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minv = INT_MAX;
        for (int p : prices) {
            if (p < minv) minv = p;
            if (p - minv > res) res = p - minv;
        }
        return res;
    }
};
