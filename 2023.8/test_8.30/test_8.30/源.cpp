#include <iostream>
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> ret;

        queue<TreeNode*> q;

        int levelSize = 0;

        if (root)
        {
            q.push(root);

            levelSize = 1;;
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

            ret.push_back(levelV);

            levelSize = q.size();
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};


int main()
{


    return 0;
}