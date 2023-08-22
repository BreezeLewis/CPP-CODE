#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution
{
public:
	void InOrderConvert(TreeNode* cur, TreeNode*& prev)
	{
		if (cur == nullptr)
			return;

		InOrderConvert(cur->left, prev);

		cur->left = prev;

		if (prev)
			prev->right = cur;

		prev = cur;

		InOrderConvert(cur->right, prev);

	}
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNode* prev = nullptr;
		InOrderConvert(pRootOfTree, prev);

		TreeNode* head = pRootOfTree;
		while (head && head->left)
			head = head->left;

		return head;
	}
};


int main()
{

	return 0;
}