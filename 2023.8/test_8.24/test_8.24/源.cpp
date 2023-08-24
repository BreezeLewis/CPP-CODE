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
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& posi, int ibegin, int iend)
    {
        if (ibegin > iend)
            return nullptr;

        int rooti = ibegin;
        while (rooti <= iend)
        {
            if (postorder[posi] == inorder[rooti])
                break;
            rooti++;;
        }

        TreeNode* root = new TreeNode(postorder[posi--]);

        root->right = _buildTree(inorder, postorder, posi, rooti + 1, iend);
        root->left = _buildTree(inorder, postorder, posi, ibegin, rooti - 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int posi = postorder.size() - 1;

        return _buildTree(inorder, postorder, posi, 0, inorder.size() - 1);
    }
};

int main()
{

    return 0;
}