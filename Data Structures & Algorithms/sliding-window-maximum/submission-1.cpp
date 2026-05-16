class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        vector<int> res;

        for (int i = 0; i < k; i++) {
            if (dq.empty()) dq.push_back(make_pair(i, nums[i]));
            else {
                while (!dq.empty() && dq.back().second < nums[i]) {
                    dq.pop_back();
                }
                dq.push_back(make_pair(i, nums[i]));
            }
        }

        res.push_back(dq.front().second);

        for (int i = k; i < nums.size(); i++) {
            while (!dq.empty() && dq.front().first <= i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && dq.back().second < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(make_pair(i, nums[i]));
            res.push_back(dq.front().second);
        }

        return res;
    }
};
