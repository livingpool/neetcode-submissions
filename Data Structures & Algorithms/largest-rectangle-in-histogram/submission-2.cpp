class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, n = heights.size();
        stack<pair<int, int>> s;

        for (int i = 0; i < n; i++) {
            if (s.empty()) s.push(make_pair(i, heights[i]));
            else if (s.top().second <= heights[i]) {
                s.push(make_pair(i, heights[i]));
            } else {
                while (!s.empty() && s.top().second > heights[i]) {
                    pair<int, int> p1 = s.top();
                    s.pop();

                    if (!s.empty()) {
                        int area = (i - s.top().first - 1) * p1.second;
                        res = max(res, area);
                    } else {
                        int area = i * p1.second;
                        res = max(res, area);
                    }
                }

                s.push(make_pair(i, heights[i]));
            }
        }

        while (!s.empty()) {
            pair<int, int> p1 = s.top();
            s.pop();

            if (!s.empty()) {
                int area = (n - s.top().first - 1) * p1.second;
                res = max(res, area);
            } else {
                int area = n * p1.second;
                res = max(res, area);
            }
        }

        return res;
    }
};
