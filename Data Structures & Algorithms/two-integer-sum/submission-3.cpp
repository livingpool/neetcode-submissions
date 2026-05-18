class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, pair<int, int>> m;
        int n = nums.size(); 
        for (int i = 0; i < n; i++) {
            if (!m.count(nums[i])) {
                m[nums[i]] = {i, i};
            } else if (m[nums[i]].first == m[nums[i]].second) {
                m[nums[i]].second = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (m.count(target - nums[i])) {
                if (target - nums[i] == nums[i]) {
                    int a = m[nums[i]].first, b = m[nums[i]].second;
                    if (a != b) return {a, b};
                    else continue;
                } else {
                    int a = m[nums[i]].first, b = m[target - nums[i]].first;
                    return {a, b};
                }
            }
        }
        return {};
    }
};
