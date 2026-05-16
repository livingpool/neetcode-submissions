class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int, int> s1_map;
        for (char s : s1) {
            if (s1_map.count(s-'a')) {
                s1_map[s-'a'] += 1;
            } else {
                s1_map[s-'a'] = 1;
            }
        }

        int n = s1.size();
        int curr = 0, l = 0, r = 0;
        vector<int> vs2(26);

        for (r; r < s2.size(); r++) {
            if (s1_map.count(s2[r] - 'a')) {
                vs2[s2[r] - 'a'] += 1;
                while (l < r) {
                    if (vs2[s2[r] - 'a'] <= s1_map[s2[r] - 'a']) break;
                    vs2[s2[l] - 'a'] -= 1;
                    l++;
                }
                if (r - l + 1 == n) return true;
            } else {
                for (int i = l; i <= r; i++) {
                    vs2[s2[i] - 'a'] = 0;
                }
                l = r + 1;
            }
        }

        return false;
    }
};
