class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size(), m = matrix[0].size();

        int l = 0, r = m - 1, t = 0, b = n - 1;
        while (res.size() < n * m) {
            for (int j = l; j <= r; j++) res.push_back(matrix[t][j]);
            t++;
            for (int i = t; i <= b; i++) res.push_back(matrix[i][r]);
            r--;

            if (t > b || l > r) break;

            for (int j = r; j >= l; j--) res.push_back(matrix[b][j]);
            b--;
            for (int i = b; i >= t; i--) res.push_back(matrix[i][l]);
            l++;
        }  

        return res;
    }
};
