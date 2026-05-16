class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        double res;
        if (n > 0) res = x;
        else {
            n = -n;
            x = 1/x;
            res = x;
        }
        for (int i = 1; i < n; i++) {
            res *= x;
        }

        return res;
    }
};
