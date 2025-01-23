#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// �������ڵ�Ķ���
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // �����Ĳ������������һά����
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

    // ���׵Ĳ�����������ض�ά���飬ÿ����һ��������
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();  // ��ǰ��Ľڵ���
            vector<int> currentLevel;

            // ����ǰ������нڵ�
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

// ���ڹ��������õĶ�����
TreeNode* createTestTree() {
    /*
        �������¶�������
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

// �ͷŶ������ڴ�
void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// ��ӡ����ĸ�������
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
    // ���������õĶ�����
    TreeNode* root = createTestTree();

    Solution solution;

    // ���Ի����Ĳ������
    cout << "Basic Level Order Traversal:" << endl;
    vector<int> basicResult = solution.levelOrderBasic(root);
    for (int val : basicResult) {
        cout << val << " ";
    }
    cout << endl << endl;

    // ���Խ��׵Ĳ��������������飩
    vector<vector<int>> result = solution.levelOrder(root);
    printResult(result);

    // �����ڴ�
    deleteTree(root);

    return 0;
}