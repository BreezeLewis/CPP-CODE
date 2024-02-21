#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> printFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);

        while (q.size()) {
            auto t = q.front();
            q.pop();
            res.push_back(t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }

        return res;
    }
};

int main()
{


	return 0;
}