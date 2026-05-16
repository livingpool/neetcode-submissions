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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> curr;
            while (n > 0) {
                if (q.front()) {
                    curr.push_back(q.front()->val);
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                    q.pop();
                } else {
                    q.pop();
                }
                n--;
            }

            if (curr.size() > 0) res.push_back(curr);
        }

        return res;
    }
};
