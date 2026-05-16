class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1) return 1;
        vector<vector<int>> dp(m, vector<int>(n, 0));    
        for (int j = n-2; j >= 0; j--) {
            dp[m-1][j] = 1;
        }
        for (int i = m-2; i >= 0; i--) {
            dp[i][n-1] = 1;
        }
        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                int down = i < m-1 ? dp[i+1][j] : 0;
                int right = j < n-1 ? dp[i][j+1] : 0;
                dp[i][j] = down + right;
            }
        }
        return dp[0][0];
    } 
};
