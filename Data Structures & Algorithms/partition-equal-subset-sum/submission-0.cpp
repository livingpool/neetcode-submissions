class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> sums;

        int target = 0;
        for (int num : nums) target += num;
        if (target % 2 != 0) return false;
        target /= 2;

        for (int num : nums) {
            unordered_set<int> newSums;
            newSums.insert(num);
            for (int i : sums) {
                newSums.insert(i);
                newSums.insert(num + i);
            }
            sums = newSums;
            if (sums.count(target)) return true;
        }
        return false;
    }
};
