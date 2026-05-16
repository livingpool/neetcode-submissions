class Solution {
public:
    string minWindow(string s, string t) {
        int want = t.size();
        unordered_map<char, int> tMap; // char, count
        for (char c : t) tMap[c]++;

        unordered_map<char, int> sMap; // char, count
        int l = 0, r = 0, have = 0;
        int resStart = -1, resLen = INT_MAX;
        while (r < s.size()) {
            if (tMap.count(s[r])) {
                sMap[s[r]]++;
                if (sMap[s[r]] <= tMap[s[r]]) have++;

                if (have == want) {
                    while (true) {
                        cout << l << ", " << r << endl;
                        if (r - l + 1 < resLen) {
                            resStart = l;
                            resLen = r - l + 1;
                        }

                        if (tMap.count(s[l])) {
                            sMap[s[l]]--;
                            if (sMap[s[l]] < tMap[s[l]]) {
                                have--;
                                l++;
                                break;
                            }
                        }
                        l++;
                    }
                }
            }

            r++;
        }

        if (resStart == -1) return "";
        return s.substr(resStart, resLen);
    }
};
