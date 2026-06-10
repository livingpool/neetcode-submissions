class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        if (n == 3) return max(max(nums[0], nums[1]), nums[2]);

        int third = nums[n-2];
        int second = nums[n-3];
        int first = nums[n-4] + third;
        for (int i = n - 5; i >= 0; i--) {
            int curr = nums[i] + max(second, third);
            third = second;
            second = first;
            first = curr;
        }
        int res1 = max(first, second);

        third = nums[n-1];
        second = nums[n-2];
        first = nums[n-3] + third;
        for (int i = n - 4; i >= 1; i--) {
            int curr = nums[i] + max(second, third);
            third = second;
            second = first;
            first = curr;
        }
        int res2 = max(first, second);

        return max(res1, res2);
    }
};
