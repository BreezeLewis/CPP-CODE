#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while (cur || !st.empty())
        {
            while (cur)
            {
                ret.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }

            TreeNode* top = st.top();
            st.pop();

            cur = top->right;
        }

        return ret;
    }
};

int main()
{

    return 0;

}