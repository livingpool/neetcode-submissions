class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> m;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (!m.count(key)) {
            vector<pair<string, int>> newV;
            newV.push_back(make_pair(value, timestamp));
            m[key] = newV;
        } else {
            m[key].push_back(make_pair(value, timestamp));
        }
    }
    
    string get(string key, int timestamp) {
        if (!m.count(key)) return "";

        vector<pair<string, int>> v = m[key];
        int l = 0, r = v.size() - 1;
        string res = "";

        while (l <= r) {
            int m = (l + r) / 2;
            if (v[m].second <= timestamp) {
                res = v[m].first;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return res;
    }
};
