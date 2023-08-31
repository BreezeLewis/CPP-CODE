#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution
{
public:
	bool GetPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
	{
		if (root == nullptr)
			return false;

		path.push(root);

		if (root == x)
			return true;

		if (GetPath(root->left, x, path))
			return true;

		if (GetPath(root->right, x, path))
			return true;

		path.pop();

		return false;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		stack<TreeNode*> pPath;
		stack<TreeNode*> qPath;

		GetPath(root, p, pPath);
		GetPath(root, q, qPath);

		while (pPath.size() != qPath.size())
			if (pPath.size() > qPath.size())
				pPath.pop();
			else
				qPath.pop();

		while (pPath.top() != qPath.top())
			pPath.pop(), qPath.pop();


		return pPath.top();
	}
};

int main()
{


	return 0;
}