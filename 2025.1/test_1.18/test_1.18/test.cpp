#include <algorithm>
#include <iostream>

using namespace std;

// 二叉树节点的定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // 获取树的高度，如果不平衡则返回-1
    int getHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // 递归获取左子树高度
        int leftHeight = getHeight(root->left);
        if (leftHeight == -1) {
            return -1;  // 左子树不平衡
        }

        // 递归获取右子树高度
        int rightHeight = getHeight(root->right);
        if (rightHeight == -1) {
            return -1;  // 右子树不平衡
        }

        // 检查当前节点是否平衡
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;  // 高度差超过1，不平衡
        }

        // 返回当前树的高度
        return max(leftHeight, rightHeight) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};

// 测试代码
int main() {
    // 创建一个平衡二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    bool isBalanced = solution.isBalanced(root);

    if (isBalanced) {
        cout << "This is a balanced binary tree." << endl;
    }
    else {
        cout << "This is not a balanced binary tree." << endl;
    }

    // 注意：实际使用时需要释放内存
    // 这里省略删除树节点的代码
    return 0;
}