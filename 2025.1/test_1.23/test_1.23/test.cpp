#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 二叉树节点的定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 基本的层序遍历，返回一维数组
    vector<int> levelOrderBasic(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node->val);

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }

        return result;
    }

    // 进阶的层序遍历，返回二维数组，每层是一个子数组
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();  // 当前层的节点数
            vector<int> currentLevel;

            // 处理当前层的所有节点
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            result.push_back(currentLevel);
        }

        return result;
    }
};

// 用于构建测试用的二叉树
TreeNode* createTestTree() {
    /*
        构建如下二叉树：
              1
             / \
            2   3
           / \   \
          4   5   6
             /
            7
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);

    return root;
}

// 释放二叉树内存
void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// 打印结果的辅助函数
void printResult(const vector<vector<int>>& result) {
    cout << "Level Order Traversal:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "Level " << i << ": ";
        for (int val : result[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // 创建测试用的二叉树
    TreeNode* root = createTestTree();

    Solution solution;

    // 测试基本的层序遍历
    cout << "Basic Level Order Traversal:" << endl;
    vector<int> basicResult = solution.levelOrderBasic(root);
    for (int val : basicResult) {
        cout << val << " ";
    }
    cout << endl << endl;

    // 测试进阶的层序遍历（按层分组）
    vector<vector<int>> result = solution.levelOrder(root);
    printResult(result);

    // 清理内存
    deleteTree(root);

    return 0;
}