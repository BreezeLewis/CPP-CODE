#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution
{
public:
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prei, int ibegin, int iend)
    {
        if (ibegin > iend)
            return nullptr;

        int rooti = ibegin;
        while (rooti <= iend)
        {
            if (preorder[prei] == inorder[rooti])
                break;
            rooti++;
        }

        TreeNode* root = new TreeNode(preorder[prei++]);

        root->left = _buildTree(preorder, inorder, prei, ibegin, rooti - 1);
        root->right = _buildTree(preorder, inorder, prei, rooti + 1, iend);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int prei = 0;
        return _buildTree(preorder, inorder, prei, 0, inorder.size() - 1);
    }
};