class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int third = nums[n-1];
        int second = nums[n-2];
        int first = nums[n-3] + third;
        for (int i = n - 4; i >= 0; i--) {
            int curr = nums[i] + max(second, third);
            third = second;
            second = first;
            first = curr;
        }
        return max(first, second);
    }
};
