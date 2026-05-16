class Solution {
private:
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& comb, int i, int target) {
        if (target < 0 || i >= nums.size()) return;
        if (target == 0) {
            res.push_back(comb);
            return;
        }

        comb.push_back(nums[i]);
        dfs(res, nums, comb, i, target - nums[i]);
        comb.pop_back();
        dfs(res, nums, comb, i + 1, target);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        dfs(res, nums, comb, 0, target);
        return res;
    }
};
