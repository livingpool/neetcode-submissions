class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> freqs;
        for (char c : s) {
            freqs[c]++;
        }
        unordered_map<char, int> freqt;
        for (char c : t) {
            freqt[c]++;
        }
        for (auto it = freqs.begin(); it != freqs.end(); it++) {
            if (freqt[(*it).first] != (*it).second) return false;
        }
        return true;
    }
};
