class Solution {
public:
    vector<int> pos;   

    string encode(vector<string>& strs) {
        string res = "";
        for (string s : strs) {
            int count = s.size();
            pos.push_back(count);
            res += s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        for (int p : pos) {
            res.push_back(s.substr(0, p));
            s.erase(0, p);
        }
        return res;
    }
};
