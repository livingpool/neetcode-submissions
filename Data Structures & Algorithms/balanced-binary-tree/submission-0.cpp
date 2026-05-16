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
    int dfs(TreeNode* root, bool& res) {
        if (root == nullptr) return 0;
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        res = res && (abs(left - right) <= 1);

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool result = true;
        dfs(root, result);
        return result;
    }
};
