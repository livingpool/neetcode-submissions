class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int l = 0, r = n - 1;
        if (nums[l] < nums[r]) return nums[0];

        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] >= nums[0]) {
                l = m + 1;
            } else if (nums[m] <= nums[n-1]) {
                r = m - 1;
            }
        }

        return nums[l];
    }
};
