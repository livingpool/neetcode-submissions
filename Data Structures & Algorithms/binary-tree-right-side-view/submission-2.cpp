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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;

        if (!root) return res;

        q.push(root);
        while (!q.empty()) {
            int n = q.size(), i = n;
            while (i) {
                if (i == n) res.push_back(q.front()->val);
                if (q.front()->right) q.push(q.front()->right);
                if (q.front()->left) q.push(q.front()->left);
                q.pop();
                i--;
            }
        }

        return res;
    }
};
