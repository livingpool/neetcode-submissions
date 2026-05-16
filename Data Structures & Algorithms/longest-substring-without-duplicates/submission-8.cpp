class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> m;
        int l = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (m.count(s[i])) { // found 
                if (m[s[i]] < l) {
                    m[s[i]] = i;
                    continue;
                }
                if (i - l > res) res = i - l;
                l = m[s[i]] + 1;
                m[s[i]] = i;
            } else { // not found
                m[s[i]] = i;
                if (i == s.size() - 1 && i - l + 1 > res)
                res = i - l + 1;
            } 
        }

        return res;
    }
};
