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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        else if (p == nullptr || q == nullptr) return false;
        queue<TreeNode*> pq;
        queue<TreeNode*> qq;

        pq.push(p);
        qq.push(q);

        while (!pq.empty() && !qq.empty()) {
            if (pq.front()->val != qq.front()->val) return false;
            if (pq.front()->left != nullptr && qq.front()->left != nullptr) {
                pq.push(pq.front()->left);
                qq.push(qq.front()->left);
            } else if (pq.front()->left == nullptr && qq.front()->left == nullptr) {}
            else return false;

            if (pq.front()->right != nullptr && qq.front()->right != nullptr) {
                pq.push(pq.front()->right);
                qq.push(qq.front()->right);
            } else if (pq.front()->right == nullptr && qq.front()->right == nullptr) {}
            else return false;

            pq.pop();
            qq.pop();
        }

        if (!pq.empty() || !qq.empty()) return false;

        return true;
    }
};
