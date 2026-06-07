class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars; // position, speed
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end()); // cars sorted by position

        stack<pair<int, int>> fleet;
        fleet.push(cars[n-1]);
        for (int i = n - 2; i >= 0; i--) {
            double t1 = (target - fleet.top().first) / (double)fleet.top().second;
            double t2 = (target - cars[i].first) / (double)cars[i].second;
            if (t1 < t2) {
                fleet.push(cars[i]);
            }
        }
        return fleet.size();
    }
};
