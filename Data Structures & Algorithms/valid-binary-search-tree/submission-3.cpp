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
    bool dfs(TreeNode* root, int maxLimit, int minLimit) {
        if (!root) return true;
        if (root->val >= maxLimit || root->val <= minLimit) return false;

        return dfs(root->left, min(maxLimit, root->val), minLimit)
            && dfs(root->right, maxLimit, max(minLimit, root->val));
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MAX, INT_MIN);
    }
};
