class Solution {
public:
    static bool sortCars(pair<int, int>& p1, pair<int, int> p2) {
        return p1.first < p2.first;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int res = 1, n = position.size();
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back(make_pair(position[i], speed[i]));
        }

        sort(cars.begin(), cars.end(), sortCars);

        float timeLimit = (target - cars[n-1].first) / float(cars[n-1].second);

        for (int i = n - 2; i >= 0; i--) {
            float currLimit = (target - cars[i].first) / float(cars[i].second);
            if (currLimit > timeLimit) {
                res += 1;
                timeLimit = currLimit;
            }
        }

        return res;
    }
};
