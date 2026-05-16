class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1;
        
        pair<int, int> pivot = make_pair(-1, INT_MAX);
        if (nums[l] > nums[r]) {
            while (l <= r) {
                int m = (l + r) / 2;
                if (nums[m] < pivot.second) {
                    pivot.first = m;
                    pivot.second = nums[m];
                }

                if (nums[m] >= nums[0]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }

        if (pivot.first != -1) {
            if (target <= nums[n-1]) {
                l = pivot.first;
                r = n - 1;
            } else {
                l = 0;
                r = pivot.first - 1;
            }
        }

        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] > target) {
                r = m - 1;
            } else if (nums[m] < target) {
                l = m + 1;
            } else return m;
        }

        return -1;
    }
};
