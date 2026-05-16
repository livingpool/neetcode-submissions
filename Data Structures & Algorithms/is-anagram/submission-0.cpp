class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); i++) {
            if (!map1.count(s[i])) map1[s[i]] = 1;
            else map1[s[i]] += 1;
        }

        for (int i = 0; i < t.size(); i++) {
            if (!map2.count(t[i])) map2[t[i]] = 1;
            else map2[t[i]] += 1;

            if (map2[t[i]] > map1[t[i]] || !map1.count(t[i])) return false;
        }
        return true;
    }
};
