class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, l = 0, r = 0;
        unordered_map<char, int> m; // char, index

        int n = s.size();
        while (r < n) {
            if (!m.count(s[r])) {
                m[s[r]] = r;
                r++;
            } else {
                res = max(res, r - l);
                l = max(m[s[r]] + 1, l);
                m[s[r]] = r;
                r++;
            }
        }

        cout << res;

        return max(res, r - l);
    }
};
