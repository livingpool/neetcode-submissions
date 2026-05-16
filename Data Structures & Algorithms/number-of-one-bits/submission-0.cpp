class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bit = 0;
        int res = 0;

        while (n > 0) {
            bit = n & 1;
            if (bit) res++;
            n = n >> 1;
        }
        return res;
    }
};
