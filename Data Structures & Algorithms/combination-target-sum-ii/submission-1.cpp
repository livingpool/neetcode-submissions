class Solution {
private:
    void dfs(vector<vector<int>>& res, vector<int>& cand, vector<int> subset, int next, int target) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }

        if (next >= cand.size() || target < 0) return;

        subset.push_back(cand[next]);
        dfs(res, cand, subset, next + 1, target - cand[next]);
        subset.pop_back();

        for (int i = next + 1; i < cand.size(); i++) {
            if (cand[i] != cand[next]) {
                dfs(res, cand, subset, i, target);
                break;
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        dfs(res, candidates, {}, 0, target);
        return res;
    }
};
