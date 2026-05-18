class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int n : nums) {
            if (s.count(n)) return true;
            else s.insert(n);
        }
        return false;
    }
};