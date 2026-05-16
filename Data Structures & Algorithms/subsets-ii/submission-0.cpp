class Solution {
private:
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int> subset, int start) {
        res.push_back(subset);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            dfs(res, nums, subset, i + 1);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        dfs(res, nums, {}, 0);
        return res;
    }
};
