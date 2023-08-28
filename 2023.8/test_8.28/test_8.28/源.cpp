#include <iostream>
#include <string>
using namespace std;


struct TreeNode 
{
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
    void _tree2str(TreeNode* cur, string& ret)
    {
        if (cur == nullptr)
            return;

        ret += to_string(cur->val);

        if (cur->left)
        {
            ret += '(';
            _tree2str(cur->left, ret);
            ret += ')';
        }
        else if (cur->right)
        {
            ret += "()";
        }

        if (cur->right)
        {
            ret += '(';
            _tree2str(cur->right, ret);
            ret += ')';
        }
    }
    string tree2str(TreeNode* root)
    {
        string ret;

        _tree2str(root, ret);

        return ret;
    }
};