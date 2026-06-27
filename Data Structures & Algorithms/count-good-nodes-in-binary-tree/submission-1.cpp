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
    int goodNodes(TreeNode* root) {
        return dfs(root, -100);
    }

    int dfs(TreeNode* root, int maxV) {
        if (root == nullptr) return 0;
        int res = 0;
        if (root->val >= maxV) {
            maxV = root->val;
            res++;
        }

        res += dfs(root->left, maxV);
        res += dfs(root->right, maxV);
        return res;
    }
};
