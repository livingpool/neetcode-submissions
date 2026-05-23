class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), l = 0, r = 1, res = 1;
        if (n == 0) return 0;
        unordered_set<char> m;
        m.insert(s[0]);

        while (r != n) {
            if (!m.count(s[r])) {
                m.insert(s[r]);
                res = max(res, r - l + 1);
            } else {
                while (s[l] != s[r]) {
                    m.erase(s[l]);
                    l++;
                }
                l++;
            }
            r++;
        }
        return res;
    }
};
