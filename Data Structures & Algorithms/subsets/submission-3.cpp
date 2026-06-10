class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        dfs(nums, 0, res);
        return res;
    }

    void dfs(vector<int>& nums, int idx, vector<vector<int>>& curr) {
        if (idx >= nums.size()) return;
        vector<vector<int>> temp = curr;
        for (int i = 0; i < curr.size(); i++) {
            vector<int> e = curr[i];
            e.push_back(nums[idx]);
            temp.push_back(e);
        }
        curr = temp;
        dfs(nums, idx + 1, curr);
    }
};
