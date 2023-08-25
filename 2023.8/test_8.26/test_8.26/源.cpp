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
 
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }


            TreeNode* top = st.top();
            st.pop();

            ret.push_back(top->val);

            cur = top->right;
        }

        return ret;
    }
};

int main()
{

    return 0;
}