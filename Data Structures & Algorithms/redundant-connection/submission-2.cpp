class UnionFind {
    public: 
        vector<int> components;
        int distinctComponents;

        UnionFind(int n) {
            distinctComponents = n;
            for (int i = 0; i < n; i++) {
                components.push_back(i);
            }
        }

        bool unite(int a, int b) {
            if (findComponent(a) == findComponent(b)) return false;

            components[findComponent(a)] = b;
            distinctComponents--;
            return true;
        }

        int findComponent(int a) {
            if (components[a] != a) {
                components[a] = findComponent(components[a]);
            }
            return components[a];
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind* u = new UnionFind(edges.size());
        for (auto& e : edges) {
            if (!u->unite(e[0] - 1, e[1] - 1)) return e;
        }     
        return {};
    }
};
