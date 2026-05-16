class Solution {
public:
    map<int, vector<int>> m;
    set<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto& p : prerequisites) {
            m[p[0]].push_back(p[1]);
        }

        for (auto& kv : m) {
            if (!dfs(kv.first)) return false;
        }
        return true;
    }

    bool dfs(int node) {
        if (m[node].empty()) return true;
        if (visited.count(node)) return false;
        
        visited.insert(node);
        for (int i : m[node]) {
            if (!dfs(i)) return false;
        }
        visited.erase(node);

        m[node].clear();
        return true;
    }
};
