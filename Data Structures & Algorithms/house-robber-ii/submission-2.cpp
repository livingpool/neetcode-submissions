class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int p = nums[n - 2], pp = 0, res = p;
        for (int i = n - 3; i >= 0; i--) {
            int curr = max(nums[i] + pp, p);
            res = max(res, curr);
            pp = p;
            p = curr;
        }

        p = nums[n - 1];
        res = max(res, p);
        pp = 0;
        for (int i = n - 2; i >= 1; i--) {
            int curr = max(nums[i] + pp, p);
            res = max(res, curr);
            pp = p;
            p = curr;
        }
        return res;
    }
};
