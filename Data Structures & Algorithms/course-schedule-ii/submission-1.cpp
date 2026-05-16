class Solution {
public:
    unordered_set<int> visited;
    unordered_set<int> exploring;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses + 1);
        for (auto& p : prerequisites) {
            adj[p[0]].push_back(p[1]);
        }    
        
        vector<int> res;
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(adj, i, res)) return {};
        }
        return res;
    }

    bool dfs(vector<vector<int>>& adj, int src, vector<int>& res) {
        if (visited.count(src)) return true;
        if (exploring.count(src)) return false;

        exploring.insert(src);
        for (int nei : adj[src]) {
            if (!dfs(adj, nei, res)) return false;
        }
        exploring.erase(src);
        adj[src].clear();
        visited.insert(src);
        res.push_back(src);
        return true;
    }
};
