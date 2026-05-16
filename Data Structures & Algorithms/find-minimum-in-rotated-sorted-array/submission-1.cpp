class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size(), l = 0, r = n - 1;
        int res = nums[0];
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= nums[0]) {
                l = mid + 1;
            } else {
                res = min(res, nums[mid]);
                r = mid - 1;
            }
        }

        return res;
    }
};
