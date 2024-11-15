#include <iostream>
using namespace std;
int n;

//先序遍历
inline void preorder(int t) {
    printf("%d ", t);
    if (t + t <= n)
        preorder(t + t);
    if (t + t + 1 <= n)
        preorder(t + t + 1);
}

//中序遍历
inline void inorder(int t) {
    if (t + t <= n)
        inorder(t + t);
    printf("%d ", t);
    if (t + t + 1 <= n)
        inorder(t + t + 1);
}

//后序遍历
inline void postorder(int t) {
    if (t + t <= n)
        postorder(t + t);
    if (t + t + 1 <= n)
        postorder(t + t + 1);
    printf("%d ", t);
}

int main() {
    cin >> n;
    preorder(1);
    cout << endl;
    inorder(1);
    cout << endl;
    postorder(1);
    cout << endl;
}