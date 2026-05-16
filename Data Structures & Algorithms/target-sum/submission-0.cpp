class Solution {
public:
    map<pair<int, int>, int> m; // {index, target}, res

    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0);
    }

    int dfs(vector<int>& nums, int target, int idx) {
        if (idx == nums.size()) {
            if (target == 0) return 1;
            else return 0;
        }

        if (m.count({idx, target})) return m[{idx, target}];

        int res = dfs(nums, target - nums[idx], idx + 1);
        res += dfs(nums, target + nums[idx], idx + 1);
        m[{idx, target}] = res;
        return res;
    }
};
