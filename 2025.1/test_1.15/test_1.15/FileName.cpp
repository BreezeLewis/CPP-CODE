string serialize(TreeNode* root) {
    string res;
    dfs_s(root, res);
    return res;
}

void dfs_s(TreeNode* root, string& res) {
    if (!root) {
        res += "null ";//�����ǰ�ڵ�Ϊ�գ�����null��һ���ո�
        return;
    }
    res += to_string(root->val) + ' ';//�����ǰ�ڵ㲻Ϊ�գ��������ֺ�һ���ո�
    dfs_s(root->left, res);
    dfs_s(root->right, res);
}
// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    int u = 0;  //�������浱ǰ���ַ���������λ��
    return dfs_d(data, u);
}

TreeNode* dfs_d(string data, int& u) {//�����u�Ǵ������ã�����ֵ����
    if (u == data.size()) return NULL;  //����Ѿ��ﵽ���ַ�����β�ˣ����˳���
    int k = u;
    while (data[k] != ' ') k++; //k��¼��ǰ���ֵ�λ����134�Ǹ���λ�������֣�56�Ǹ���λ�������֣��˳���ʱ��kָ�����ַ����м�Ŀո����Իص��¸��ַ����ײ���Ҫ��1.

    if (data[u] == 'n') {//�����ǰ�ַ����ǡ�null��
        u = k + 1;//�ص���һ�����ֵ��ײ���ע����u = k+1, ����u = u+1;
        return NULL;//��ʾ��ι������һ��null�ڵ㣬��û�к��ӽڵ㣬������������ĵݹ�
    }
    int val = 0;
    //��������Ǹ���
    if (data[u] == '-') {
        for (int i = u + 1; i < k; i++) val = val * 10 + data[i] - '0';
        val = -val;
    }
    else {
        //���������������
        for (int i = u; i < k; i++) val = val * 10 + data[i] - '0';
    }
    u = k + 1;//�ص��¸����ֵ��ײ�
    //�ݹ��㷨������д�˳�������Ȼ��ŵݹ���á�
    auto root = new TreeNode(val);
    root->left = dfs_d(data, u);
    root->right = dfs_d(data, u);
    return root;
}

 