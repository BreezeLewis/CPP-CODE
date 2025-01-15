string serialize(TreeNode* root) {
    string res;
    dfs_s(root, res);
    return res;
}

void dfs_s(TreeNode* root, string& res) {
    if (!root) {
        res += "null ";//如果当前节点为空，保存null和一个空格
        return;
    }
    res += to_string(root->val) + ' ';//如果当前节点不为空，保存数字和一个空格
    dfs_s(root->left, res);
    dfs_s(root->right, res);
}
// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    int u = 0;  //用来保存当前的字符串遍历的位置
    return dfs_d(data, u);
}

TreeNode* dfs_d(string data, int& u) {//这里的u是传的引用，不是值传递
    if (u == data.size()) return NULL;  //如果已经达到了字符串的尾端，则退出。
    int k = u;
    while (data[k] != ' ') k++; //k记录当前数字的位数如134是个三位数的数字，56是个两位数的数字，退出的时候，k指向了字符的中间的空格，所以回到下个字符的首部需要加1.

    if (data[u] == 'n') {//如果当前字符串是“null”
        u = k + 1;//回到下一个数字的首部，注意是u = k+1, 不是u = u+1;
        return NULL;//表示这次构造的是一个null节点，并没有孩子节点，所以跳过后面的递归
    }
    int val = 0;
    //如果数字是负的
    if (data[u] == '-') {
        for (int i = u + 1; i < k; i++) val = val * 10 + data[i] - '0';
        val = -val;
    }
    else {
        //如果是数字是正的
        for (int i = u; i < k; i++) val = val * 10 + data[i] - '0';
    }
    u = k + 1;//回到下个数字的首部
    //递归算法总是先写退出条件，然后才递归调用。
    auto root = new TreeNode(val);
    root->left = dfs_d(data, u);
    root->right = dfs_d(data, u);
    return root;
}

 