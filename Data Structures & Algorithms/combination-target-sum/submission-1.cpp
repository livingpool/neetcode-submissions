class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> res;
        dfs(nums, 0, subset, res, target);
        return res;
    }

    void dfs(vector<int>& nums, int idx, vector<int>& subset, vector<vector<int>>& res, int target) {
        if (target == 0) {
            res.push_back(subset);
            return;
        } else if (target < 0 || idx >= nums.size()) {
            return;
        }
        subset.push_back(nums[idx]);
        dfs(nums, idx, subset, res, target - nums[idx]);
        subset.pop_back();
        dfs(nums, idx + 1, subset, res, target);
    }
};
