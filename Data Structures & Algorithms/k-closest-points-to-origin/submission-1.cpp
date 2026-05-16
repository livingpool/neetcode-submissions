class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;    
        auto comp = [](const vector<int>& p1, const vector<int>& p2) {
            return pow(p1[0], 2) + pow(p1[1], 2) < pow(p2[0], 2) + pow(p2[1], 2);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> maxHeap(comp);

        for (auto& v : points) {
            maxHeap.push(v);
            if (maxHeap.size() > k) maxHeap.pop();
        }

        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return res;
    }
};
