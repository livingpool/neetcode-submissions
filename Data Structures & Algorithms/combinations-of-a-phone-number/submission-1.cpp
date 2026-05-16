class Solution {
private:
    unordered_map<char, string> m = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void dfs(vector<string>& res, string s, string digits, int p) {
        if (s.size() == digits.size()) res.push_back(s);
        for (int i = p; i < digits.size(); i++) {
            string curr = m[digits[i]];
            for (int j = 0; j < curr.size(); j++) {
                dfs(res, s + curr[j], digits, i + 1);
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits == "") return {};
        dfs(res, "", digits, 0);
        return res;
    }
};
