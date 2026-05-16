class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        // count `count` of each number 
        for (int n : nums) 
            count[n] = count[n] + 1;

        // put each number into corresponding buckets
        for (const auto& entry : count) 
            freq[entry.second].push_back(entry.first);

        // iterate freq k times
        for (int i = freq.size() - 1; i >= 0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) return res;
            }
        }
        
        return res;
    }
};
