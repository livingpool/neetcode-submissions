class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> s;

        for (int i = n-1; i >= 0; i--) {
            if (s.empty()) {
                s.push(make_pair(i, temperatures[i]));
                res[i] = 0;
            } else {
                if (s.top().second > temperatures[i]) {
                    res[i] = s.top().first - i;
                    s.push(make_pair(i, temperatures[i]));
                } else {
                    while (!s.empty() && s.top().second <= temperatures[i]) {
                        s.pop();
                    }

                    if (s.empty()) {
                        res[i] = 0;
                        s.push(make_pair(i, temperatures[i]));
                    } else {
                        res[i] = s.top().first - i;
                        s.push(make_pair(i, temperatures[i]));
                    }
                }
            }
        }

        return res;
    }
};
