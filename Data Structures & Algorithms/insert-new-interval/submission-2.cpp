class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        bool is_new_pushed = false;
        for (int i = 0; i < n; i++) {
            if (newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                if (!is_new_pushed) {
                    res.push_back(newInterval);
                }
                is_new_pushed = true;
                res.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        if (!is_new_pushed) {
            res.push_back(newInterval);
        }
        return res;
    }
};
