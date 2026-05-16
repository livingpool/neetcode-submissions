class Solution {
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right], p = left;
        for (int i = left; i < right; i++) {
            if (nums[i] <= pivot) {
                swap(nums[p++], nums[i]);
            }
        }
        swap(nums[p], nums[right]);
        return p;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int pivot = partition(nums, left, right);
            if (pivot > k) right = pivot - 1;
            else if (pivot < k) left = pivot + 1;
            else break;
        }

        return nums[k];
    }
};
