/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            if (!q.front()) res += "##";
            else {
                res = res + "#" + to_string(q.front()->val);
                q.push(q.front()->left);
                q.push(q.front()->right);
            }
            q.pop();
        }

        cout << res << endl;

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int l = 1, r = 1, n = data.size();
        queue<TreeNode*> q;

        while (l < n && r < n) {
            while (data[r] != '#') r++;
            if (r == l) {
                q.push(nullptr);
                r += 2;
                l = r;
            }
            else {
                cout << l << ", " << r << endl;
                cout << data.substr(l, r - l) << endl;
                int value = stoi(data.substr(l, r - l));
                TreeNode* newNode = new TreeNode(value);
                q.push(newNode);
                r++;
                l = r;
            }
        }

        queue<TreeNode*> q2;
        TreeNode* root = q.front();
        q2.push(q.front());
        q.pop();

        while (!q2.empty()) {
            if (q2.front() != nullptr) {
                TreeNode* n1 = q.front();
                q.pop();
                TreeNode* n2 = q.front();
                q.pop();

                TreeNode* r = q2.front();
                r->left = n1;
                r->right = n2;

                q2.push(n1);
                q2.push(n2);
            }
            q2.pop();
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));