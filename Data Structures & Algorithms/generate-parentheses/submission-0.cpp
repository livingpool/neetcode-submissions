class Solution {
public:
    void dfs(vector<string>& res, stack<char> s, string res_s, int l, int r, int n) {
        if (res_s.size() == n * 2) {
            res.push_back(res_s);
            return;
        }

        if (l > 0) {
            s.push('(');
            dfs(res, s, res_s + '(', l - 1, r, n);
            s.pop();
        }

        if (r > 0 && !s.empty() && s.top() == '(') {
            s.pop();
            dfs(res, s, res_s + ')', l, r - 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        stack<char> s;
        s.push('(');
        dfs(res, s, "(", n - 1, n, n);

        return res;
    }
};
