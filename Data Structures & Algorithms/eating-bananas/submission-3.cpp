class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if (n > h) return -1;

        sort(piles.begin(), piles.end());
        int l = 1, r = piles[n-1], res = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            int count = 0;
            for (int p : piles) {
                int curr = p / mid;
                if (p % mid != 0) curr++;
                count += curr;
            } 

            if (count <= h) {
                res = min(res, mid);
                r = mid - 1;
            } else l = mid + 1;
        }

        return res;
    }
};
