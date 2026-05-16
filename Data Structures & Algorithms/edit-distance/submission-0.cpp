class Solution {
public:
    map<pair<int, int>, int> cache; // pos in word1 & word2, min ops
    int minDistance(string word1, string word2) {
        return dfs(word1, word2, 0, 0);
    }

    int dfs(string& word1, string& word2, int i, int j) {
        if (i == word1.size() || j == word2.size()) {
            return max(word1.size() - i, word2.size() - j);
        }
        if (cache.count({i, j})) return cache[{i, j}];
        if (word1[i] == word2[j]) return dfs(word1, word2, i+1, j+1);

        int res = INT_MAX;
        res = min(res, 1 + dfs(word1, word2, i, j+1));
        res = min(res, 1 + dfs(word1, word2, i+1, j));
        res = min(res, 1 + dfs(word1, word2, i+1, j+1));

        cache[{i, j}] = res;
        return res;
    }
};
