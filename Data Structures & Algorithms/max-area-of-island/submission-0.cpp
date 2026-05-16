class Solution {
private:
    set<pair<int, int>> visited;
    deque<pair<int, int>> dq;
    
    int bfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        int area = 0;
        dq.push_back({i, j});
        while (!dq.empty()) {
            pair<int, int> p = dq.front();
            dq.pop_front();

            if (p.first < 0 || p.first >= n || p.second < 0 || p.second >= m) continue;
            if (grid[p.first][p.second] == 0) continue;
            if (visited.count(p)) continue;

            visited.insert(p);
            area++;

            dq.push_back({p.first + 1, p.second});
            dq.push_back({p.first - 1, p.second});
            dq.push_back({p.first, p.second + 1});
            dq.push_back({p.first, p.second - 1});
        }

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && !visited.count({i, j})) {
                    res = max(res, bfs(grid, i, j, n, m));
                }
            }
        }
        return res;
    }
};
