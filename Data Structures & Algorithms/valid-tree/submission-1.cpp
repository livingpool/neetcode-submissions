class Solution {
public:
    unordered_map<int, vector<int>> adj;
    set<int> visited;

    bool validTree(int n, vector<vector<int>>& edges) {
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // We should be able to reach every node from any single node
        if (!dfs(0, -1)) return false;

        for (int i = 0; i < n; i++) {
            if (!visited.count(i)) return false;
        }
        return true;
    }

    bool dfs(int curr, int prev) {
        if (visited.count(curr)) return false; // loop detected

        visited.insert(curr);
        for (int neighbor : adj[curr]) {
            if (neighbor != prev && !dfs(neighbor, curr)) return false;
        }

        return true;
    }
};
