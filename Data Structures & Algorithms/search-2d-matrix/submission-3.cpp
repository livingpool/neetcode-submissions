class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int l = 0, r = m - 1, row = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (matrix[mid][0] > target) {
                r = mid - 1;
            } else if (matrix[mid][n-1] < target) {
                l = mid + 1;
            } else {
                row = mid;
                break;
            }
        }

        if (row == -1) return false;

        l = 0;
        r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (matrix[row][mid] > target) r = mid - 1;
            else if (matrix[row][mid] < target) l = mid + 1;
            else return true;
        }

        return false;
    }
};
