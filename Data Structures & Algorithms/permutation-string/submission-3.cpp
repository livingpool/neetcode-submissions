class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq1;
        for (char c : s1) {
            freq1[c]++;
        }

        int n1 = s1.size(), n2 = s2.size(), l = 0, r = 0;
        if (n1 > n2) return false;
        unordered_map<char, int> freq2;

        while (r < n2) {
            char curr = s2[r];
            if (!freq1.count(curr)) {
                r++;
                while (l < r) {
                    freq2[s2[l]]--;
                    l++;
                }
            } else if (freq1[curr] > freq2[curr]) {
                freq2[curr]++;
                r++;
                if (r - l == n1) return true;
            } else {
                while (s2[l] != curr) {
                    freq2[s2[l]]--;
                    l++;
                }
                if (s2[l] != curr) {
                    freq2[s2[l]]--;
                }
                l++;
                r++;
            }
        }
        return false;
    }
};
