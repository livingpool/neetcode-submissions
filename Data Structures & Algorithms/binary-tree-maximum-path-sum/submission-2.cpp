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
private:
    int dfs(TreeNode* root, int& res) {
        if (!root) return INT_MIN;
        int maxL = dfs(root->left, res);
        int maxR = dfs(root->right, res);

        if (maxL > 0 && maxR > 0) {
            int maxLocal = max(root->val, root->val + maxL + maxR);
            res = max(res, maxLocal);
            return root->val + max(maxL, maxR);
        } else if (maxL > 0) {
            int maxLocal = max(root->val, root->val + maxL);
            res = max(res, maxLocal);
            return root->val + maxL;
        } else if (maxR > 0) {
            int maxLocal = max(root->val, root->val + maxR);
            res = max(res, maxLocal);
            return root->val + maxR;
        } else {
            res = max(res, root->val);
            return root->val;
        }
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
};
