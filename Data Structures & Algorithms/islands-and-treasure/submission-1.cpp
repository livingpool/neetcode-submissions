class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }

        int distance = 0;
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                if (grid[p.first][p.second] >= distance) {
                    grid[p.first][p.second] = distance;
                    if (p.first + 1 < m && grid[p.first + 1][p.second] > distance + 1) q.push({p.first + 1, p.second});
                    if (p.first - 1 >= 0 && grid[p.first - 1][p.second] > distance + 1) q.push({p.first - 1, p.second});
                    if (p.second + 1 < n && grid[p.first][p.second + 1] > distance + 1) q.push({p.first, p.second + 1});
                    if (p.second - 1 >= 0 && grid[p.first][p.second - 1] > distance + 1) q.push({p.first, p.second - 1});
                }
            }
            distance++;
        }
    }
};
 