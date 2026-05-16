class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int rotations = n / 2;
        int curr = n - 1;

        for (int i = 0; i < rotations; i++) {
            vector<int> p1{i, i};
            vector<int> p2{i, n - 1 - i};
            vector<int> p3{n - 1 - i, n - 1 - i};
            vector<int> p4{n - 1 - i, i};

            for (int j = 0; j < curr; j++) {
                int tmp = matrix[p2[0]][p2[1]];
                matrix[p2[0]][p2[1]] = matrix[p1[0]][p1[1]];
                int tmp2 = matrix[p3[0]][p3[1]];
                matrix[p3[0]][p3[1]] = tmp;
                tmp = matrix[p4[0]][p4[1]];
                matrix[p4[0]][p4[1]] = tmp2;
                matrix[p1[0]][p1[1]] = tmp;

                p1[1]++;
                p2[0]++;
                p3[1]--;
                p4[0]--;
            }
            curr -= 2;
        }    
    }
};
