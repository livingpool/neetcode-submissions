class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int j = i;
            while (j > 0) {
                int bit = j & 1;
                if (bit) res[i]++;
                j = j >> 1;
            }
        }
        return res;
    }
};
