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
    bool inOrder(TreeNode* root, TreeNode*& prev)
    {
        if (root == nullptr) return true;

        if (!inOrder(root->left, prev)) return false;

        if (prev != nullptr && root->val <= prev->val) return false;

        prev = root;

        return inOrder(root->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return inOrder(root, prev);
    }
};