class Solution {
public:
    bool isHappy(int n) {
        set<int> seen;
        while (n > 1) {
            int sum = 0;
            while (n > 0) {
                sum += (n%10) * (n%10);
                n /= 10;
            }
            if (seen.count(sum)) return false;
            seen.insert(sum);
            n = sum;
        }        
        return true;
    }
};
