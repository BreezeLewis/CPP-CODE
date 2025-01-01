#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // �ֵ����ڵ�ṹ
    struct TrieNode {
        vector<TrieNode*> children;
        bool isEnd;
        TrieNode() : children(26, nullptr), isEnd(false) {}
    };

    TrieNode* root;
    vector<vector<int>> graph;  // �������������ͼ
    vector<bool> visited;       // ������������ķ��ʱ��
    vector<bool> inStack;       // ���ڼ�⻷
    vector<int> result;         // �洢����������
    bool hasCycle;             // ����Ƿ���ڻ�

public:
    Solution() : root(new TrieNode()), graph(26, vector<int>()),
        visited(26, false), inStack(26, false), hasCycle(false) {
    }

    // �ֵ����Ĳ������
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

    // ���αȽ������ַ������ҳ��ַ�˳���ϵ
    void compareStrings(const string& s1, const string& s2) {
        // ʹ�÷��ε�˼�룬���ַ����Ƚ�����ֽ�Ϊ�ַ��Ƚ�
        int i = 0;
        int len1 = s1.length(), len2 = s2.length();
        while (i < len1 && i < len2) {
            if (s1[i] != s2[i]) {
                // �ҵ���һ����ͬ���ַ�����ӱߵ�ͼ��
                int from = s1[i] - 'a';
                int to = s2[i] - 'a';
                graph[from].push_back(to);
                return;
            }
            i++;
        }
        // �������һ���ַ�������һ����ǰ׺���ҽϳ����ַ�����ǰ
        if (i < len1 && i >= len2) {
            hasCycle = true; // ��������ǲ��Ϸ���
        }
    }

    // ���������DFSʵ��
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
        // �����ֵ���
        for (const string& word : words) {
            insertWord(word);
        }

        // ���αȽ������ַ���
        for (int i = 0; i < words.size() - 1; i++) {
            compareStrings(words[i], words[i + 1]);
            if (hasCycle) return "Impossible";
        }

        // ִ����������
        for (int i = 0; i < 26; i++) {
            if (!visited[i]) {
                topologicalSortDFS(i);
            }
            if (hasCycle) return "Impossible";
        }

        // �������ַ���
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