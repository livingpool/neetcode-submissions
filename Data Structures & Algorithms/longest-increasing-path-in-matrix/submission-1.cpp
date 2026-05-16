class Solution {
public:
    map<pair<int, int>, int> seen; // {x, y}, LIP

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(matrix, i, j, m, n));
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j, int m, int n) {
        if (seen.count({i, j})) return seen[{i, j}];

        int res = 1;
        if (i-1 >= 0 && matrix[i-1][j] > matrix[i][j]) {
            res = max(res, 1 + dfs(matrix, i-1, j, m, n));
        }
        if (i+1 < m && matrix[i+1][j] > matrix[i][j]) {
            res = max(res, 1 + dfs(matrix, i+1, j, m, n));
        }
        if (j-1 >= 0 && matrix[i][j-1] > matrix[i][j])  {
            res = max(res, 1 + dfs(matrix, i, j-1, m, n));
        }
        if (j+1 < n && matrix[i][j+1] > matrix[i][j]) {
            res = max(res, 1 + dfs(matrix, i, j+1, m, n));
        }

        seen[{i, j}] = res;
        return res;
    }
};
