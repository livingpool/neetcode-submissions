class Solution {
private:
    set<int> col;
    set<int> posDiag;
    set<int> negDiag;

    void backtrack(vector<vector<string>>& res, vector<string> board, int n, int r) {
        if (board.size() == n) {
            res.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (col.count(c) || posDiag.count(r - c) || negDiag.count(r + c))
                continue;

            string row = "";
            for (int i = 0; i < c; i++) row += ".";
            row += "Q";
            for (int i = c + 1; i < n; i++) row += ".";

            board.push_back(row);
            col.insert(c);
            posDiag.insert(r - c);
            negDiag.insert(r + c);

            backtrack(res, board, n, r + 1);

            board.pop_back();
            col.erase(c);
            posDiag.erase(r - c);
            negDiag.erase(r + c);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        backtrack(res, {}, n, 0);
        return res;
    }
};
