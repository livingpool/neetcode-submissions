class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxP = 0;
        for (int p : piles) {
            if (p > maxP) maxP = p;
        }

        int sum = 0;
        int l = 1, r = maxP;
        while (l < r) {
            int mid = (l + r) / 2;
            for (int p : piles) {
                sum += p / mid;
                if (p % mid != 0) sum += 1;
            }

            if (sum > h) {
                l = mid + 1;
            } else if (sum <= h) {
                r = mid;
            }
            sum = 0;
        }

        return r;
    }
};
