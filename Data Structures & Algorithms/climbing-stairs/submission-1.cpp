class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int second = 1; // n-1 -> n
        int first = 2; // n-2 -> n
        for (int i = n - 3; i >= 0; i--) {
            int curr = first + second;
            second = first;
            first = curr;
        }
        return first;
    }
};
