class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;    
        digits[digits.size() - 1] += 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += carry;
            int curr = digits[i];
            digits[i] %= 10;
            if (curr >= 10) carry = 1;
            else carry = 0;
        }
        if (carry == 1) digits.insert(digits.begin(), 1);
        return digits;
    }
};
