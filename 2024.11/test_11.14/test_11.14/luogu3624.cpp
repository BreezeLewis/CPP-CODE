#include <iostream>
#include <cstdio>
using namespace std;
int n;
struct TreeNode {
    int l, r, fa;
}node[1000010];

inline void preorder(int t) {
    printf("%d ", t);
    if (node[t].l)
        preorder(node[t].l);
    if (node[t].r)
        preorder(node[t].r);
}

//中序遍历
inline void inorder(int t) {
    if (node[t].l)
        inorder(node[t].l);
    printf("%d ", t);
    if (node[t].r)
        inorder(node[t].r);
}

//后序遍历
inline void postorder(int t) {
    if (node[t].l)
        postorder(node[t].l);
    if (node[t].r)
        postorder(node[t].r);
    printf("%d ", t);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        if (x)
            node[i].l = x, node[x].fa = i;
        if (y)
            node[i].r = y, node[y].fa = i;
    }
    preorder(1); printf("\n");
    inorder(1); printf("\n");
    postorder(1); printf("\n");
    return 0;
}

