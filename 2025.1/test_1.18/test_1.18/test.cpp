#include <algorithm>
#include <iostream>

using namespace std;

// �������ڵ�Ķ���
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // ��ȡ���ĸ߶ȣ������ƽ���򷵻�-1
    int getHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // �ݹ��ȡ�������߶�
        int leftHeight = getHeight(root->left);
        if (leftHeight == -1) {
            return -1;  // ��������ƽ��
        }

        // �ݹ��ȡ�������߶�
        int rightHeight = getHeight(root->right);
        if (rightHeight == -1) {
            return -1;  // ��������ƽ��
        }

        // ��鵱ǰ�ڵ��Ƿ�ƽ��
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;  // �߶Ȳ��1����ƽ��
        }

        // ���ص�ǰ���ĸ߶�
        return max(leftHeight, rightHeight) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};

// ���Դ���
int main() {
    // ����һ��ƽ�������
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

    // ע�⣺ʵ��ʹ��ʱ��Ҫ�ͷ��ڴ�
    // ����ʡ��ɾ�����ڵ�Ĵ���
    return 0;
}