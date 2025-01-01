#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // 字典树节点结构
    struct TrieNode {
        vector<TrieNode*> children;
        bool isEnd;
        TrieNode() : children(26, nullptr), isEnd(false) {}
    };

    TrieNode* root;
    vector<vector<int>> graph;  // 用于拓扑排序的图
    vector<bool> visited;       // 用于拓扑排序的访问标记
    vector<bool> inStack;       // 用于检测环
    vector<int> result;         // 存储拓扑排序结果
    bool hasCycle;             // 标记是否存在环

public:
    Solution() : root(new TrieNode()), graph(26, vector<int>()),
        visited(26, false), inStack(26, false), hasCycle(false) {
    }

    // 字典树的插入操作
    void insertWord(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEnd = true;
    }

    // 分治比较两个字符串，找出字符顺序关系
    void compareStrings(const string& s1, const string& s2) {
        // 使用分治的思想，将字符串比较问题分解为字符比较
        int i = 0;
        int len1 = s1.length(), len2 = s2.length();
        while (i < len1 && i < len2) {
            if (s1[i] != s2[i]) {
                // 找到第一个不同的字符，添加边到图中
                int from = s1[i] - 'a';
                int to = s2[i] - 'a';
                graph[from].push_back(to);
                return;
            }
            i++;
        }
        // 如果其中一个字符串是另一个的前缀，且较长的字符串在前
        if (i < len1 && i >= len2) {
            hasCycle = true; // 这种情况是不合法的
        }
    }

    // 拓扑排序的DFS实现
    void topologicalSortDFS(int v) {
        visited[v] = true;
        inStack[v] = true;

        for (int u : graph[v]) {
            if (!visited[u]) {
                topologicalSortDFS(u);
            }
            else if (inStack[u]) {
                hasCycle = true;
            }
            if (hasCycle) return;
        }

        inStack[v] = false;
        result.push_back(v);
    }

    string solve(vector<string>& words) {
        // 构建字典树
        for (const string& word : words) {
            insertWord(word);
        }

        // 分治比较相邻字符串
        for (int i = 0; i < words.size() - 1; i++) {
            compareStrings(words[i], words[i + 1]);
            if (hasCycle) return "Impossible";
        }

        // 执行拓扑排序
        for (int i = 0; i < 26; i++) {
            if (!visited[i]) {
                topologicalSortDFS(i);
            }
            if (hasCycle) return "Impossible";
        }

        // 构造结果字符串
        string ans;
        reverse(result.begin(), result.end());
        for (int i : result) {
            ans += (char)(i + 'a');
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    Solution solution;
    string result = solution.solve(words);
    cout << result << endl;

    return 0;
}