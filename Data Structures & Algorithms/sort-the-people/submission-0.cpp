class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> m;
        for (int i = 0; i < names.size(); i++) {
            m[heights[i]] = names[i];
        }
        vector<string> res;
        sort(heights.begin(), heights.end(), greater<>());
        for (int i = 0; i < heights.size(); i++) {
            res.push_back(m[heights[i]]);
        }
        return res;
    }
};