//#include <iostream>
//using namespace std;
//typedef int T;
//struct BinaryNode {
//
//    T data;
//
//    BinaryNode* left, * right;
//
//    BinaryNode(T d, BinaryNode* l = nullptr, BinaryNode* r = nullptr) 
//        :data(d), left(l), right(r) {
//        int x = 0;
//    };
//
//};
//
//
//
//void clear(BinaryNode* root) {
//
//    if (root) {
//
//        clear(root->left);
//
//        clear(root->right);
//
//        delete root;
//
//    }
//
//}
//
//
//
//void insert(BinaryNode* root, const T& x) {
//
//    if (root == nullptr)
//
//        root = new BinaryNode(x);
//
//    else if (x < root->data)
//
//        insert(root->left, x);
//
//    else
//
//        insert(root->right, x);
//
//}
//
//
//
//int main() {
//
//    BinaryNode* root = nullptr;
//
//    insert(root, 1);
//
//    insert(root, 2);
//
//    insert(root, 3);
//
//    cout << root->data << endl;
//
//    clear(root);
//
//    return 0;
//
//}