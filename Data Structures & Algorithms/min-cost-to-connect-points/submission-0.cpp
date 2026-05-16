class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        return prim(adj, n);
    }

    int prim(vector<vector<pair<int, int>>>& adj, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        unordered_set<int> visited;
        minHeap.push({0, 0});

        int res = 0;
        while (!minHeap.empty()) {
            auto [dist, node] = minHeap.top();
            minHeap.pop();
            if (visited.count(node)) continue;

            visited.insert(node);
            res += dist;

            for (auto [nei_dist, nei] : adj[node]) {
                minHeap.push({nei_dist, nei});
            }
        }
        return res;
    }
};
