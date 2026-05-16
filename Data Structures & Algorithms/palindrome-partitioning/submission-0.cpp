class Solution {
private:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void dfs(vector<vector<string>>& res, vector<string> subset, string s, int p) {
        if (p == s.size()) res.push_back(subset);
        for (int i = p; i < s.size(); i++) {
            string curr = s.substr(p, i - p + 1);
            if (isPalindrome(curr)) {
                subset.push_back(curr);
                dfs(res, subset, s, i + 1);
                subset.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        dfs(res, {}, s, 0);
        return res;
    }
};
