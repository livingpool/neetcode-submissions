class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int second = cost[n-1];
        int first = cost[n-2];
        for (int i = n - 3; i >= 0; i--) {
            int curr = cost[i] + min(second, first);
            second = first;
            first = curr;
        }
        return min(second, first);
    }
};
