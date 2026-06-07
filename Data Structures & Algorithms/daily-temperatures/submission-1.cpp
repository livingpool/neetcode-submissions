class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<pair<int, int>> main; // val, index
        for (int i = n - 1; i >= 0; i--) {
            if (main.empty()) {
                main.push({temperatures[i], i});
            } else {
                while (!main.empty()) {
                    if (main.top().first > temperatures[i]) {
                        result[i] = main.top().second - i;
                        main.push({temperatures[i], i});
                        break;
                    }
                    main.pop();
                }
                if (main.empty()) {
                    main.push({temperatures[i], i});
                }
            }
        }
        return result;
    }
};
