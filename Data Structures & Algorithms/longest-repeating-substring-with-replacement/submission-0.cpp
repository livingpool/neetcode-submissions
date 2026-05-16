class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int l = 0, r = 0, n = s.size(), res = 0;

        while (r < n) {
            freq[s[r] - 'A'] += 1;

            int maxF = 0;
            for (int i = 0; i < 26; i++) {
                maxF = max(maxF, freq[i]);
            }

            // valid: window - maxF <= k
            while ((r - l + 1) - maxF > k) {
                freq[s[l] - 'A'] -= 1;
                l++;
                for (int i = 0; i < 26; i++) {
                    maxF = max(maxF, freq[i]);
                }
            }

            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};
