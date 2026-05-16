class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> map;
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            cout << strs[i] << endl;
            if (map.count(tmp)) res[map[tmp]].push_back(strs[i]);
            else {
                res.push_back(vector<string>{strs[i]});
                map[tmp] = res.size() - 1;
            }
        }
        return res;
    }
};
