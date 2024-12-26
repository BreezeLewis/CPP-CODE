#include "stdc++.h"
using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> edges; // �洢���յ�����
    vector<int> color;         // ���ڶ���ͼȾɫ
    vector<int> parent;        // ���鼯�ĸ��ڵ�����
    vector<vector<int>> dist;  // �洢ѯ�ʵõ��ľ���

    // ���鼯�����Ҹ��ڵ�
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    // ���鼯���ϲ���������
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) parent[px] = py;
    }

public:
    void solve() {
        // ����ڵ���
        cin >> n;
        edges.clear();
        color.resize(n + 1, -1);
        parent.resize(n + 1);
        dist.resize(n + 1, vector<int>(n + 1));

        // ��ʼ�����鼯
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // ��һ����ѯ�ʽڵ�1�����о��룬���ڶ���ͼȾɫ
        cout << "? 1" << endl;
        vector<int> d(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
            dist[1][i] = d[i];
            dist[i][1] = d[i];
        }

        // ʹ�þ������ż�Խ��ж���ͼȾɫ
        color[1] = 0;
        vector<vector<int>> levels(2); // ����ż�������
        for (int i = 2; i <= n; i++) {
            color[i] = d[i] % 2;
            levels[color[i]].push_back(i);
        }

        // ѡ���С����ɫ���Ͻ���ѯ��
        vector<int>& queryNodes = levels[levels[0].size() < levels[1].size() ? 0 : 1];

        // ��ѡ���Ľڵ㼯�Ͻ���ѯ��
        for (int node : queryNodes) {
            cout << "? " << node << endl;
            for (int i = 1; i <= n; i++) {
                cin >> d[i];
                dist[node][i] = d[i];
                dist[i][node] = d[i];
            }
        }

        // ʹ��Kruskal�㷨�ؽ���
        vector<tuple<int, int, int>> allEdges; // {distance, u, v}
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (dist[i][j] == 1) { // ֻ����ֱ�������ı�
                    allEdges.push_back({ 1, i, j });
                }
            }
        }

        // Kruskal�㷨������Ȩ����
        sort(allEdges.begin(), allEdges.end());

        // �ؽ����ṹ
        for (auto [d, u, v] : allEdges) {
            if (find(u) != find(v)) {
                unite(u, v);
                edges.push_back({ u, v });
            }
        }

        // ������
        cout << "!" << endl;
        for (const auto& edge : edges) {
            cout << edge[0] << " " << edge[1] << endl;
        }
    }
};

int main() {
    Solution solution;
    solution.solve();
    return 0;
}