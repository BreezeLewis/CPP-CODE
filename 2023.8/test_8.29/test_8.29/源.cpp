#include <iostream>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> vv;

        queue<TreeNode*> q;

        int levelSize = 0;

        if (root)
        {
            q.push(root);

            levelSize = 1;
        }

        while (!q.empty())
        {
            vector<int> levelV;

            while (levelSize--)
            {
                TreeNode* front = q.front();

                q.pop();

                levelV.push_back(front->val);

                if (front->left)
                    q.push(front->left);

                if (front->right)
                    q.push(front->right);
            }

            vv.push_back(levelV);

            levelSize = (int)q.size();
        }

        return vv;
    }
};


int main()
{


    return 0;
}