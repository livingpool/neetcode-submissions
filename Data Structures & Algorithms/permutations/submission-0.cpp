class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        // base case
        if (nums.size() == 1) {
            vector<int> singleNum;
            singleNum.push_back(nums[0]);
            res.push_back(singleNum);
            return res;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            vector<int> remains(nums.size() - 1);

            int idx = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (j != i) remains[idx++] = nums[j];
            }

            vector<vector<int>> perms = permute(remains);

            for (const auto& perm : perms) {
                vector<int> newPerm = perm;
                newPerm.push_back(num);
                res.push_back(newPerm);
            }
        }

        return res;
    }
};
