class Solution {
public:
    unordered_map<int, vector<int>> adj;
    set<int> visited;

    int countComponents(int n, vector<vector<int>>& edges) {
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!visited.count(i)) {
                dfs(i);
                res++;
            }
        }
        return res;
    }

    void dfs(int curr) {
        if (visited.count(curr)) return;

        visited.insert(curr);
        for (auto& neighbor : adj[curr]) {
            dfs(neighbor);
        }
    }
};
