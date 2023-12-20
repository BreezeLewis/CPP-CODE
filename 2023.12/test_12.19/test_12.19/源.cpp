#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Graph {
    int V; // �ڵ���
    vector<vector<int>> adj; // �ڽӱ�

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    // ��ӱߣ�����ͼ��
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // ��Ϊ������ͼ������Ҫ���˫���
    }

    // ����ڵ�Ķ�������
    vector<int> degreeSequence() {
        vector<int> degrees(V, 0);

        // ����ÿ���ڵ�Ķ���
        for (int u = 0; u < V; ++u) {
            degrees[u] = adj[u].size();
        }

        // �Զ������н��зǵ�������
        sort(degrees.rbegin(), degrees.rend());

        return degrees;
    }
};

int main() {
    fstream file;
    file.open("D:\\cxdownload\\in2.txt", ios::in);

    int N; // ����������Ŀ
    file >> N;

    while (N--) {
        int n, m; // ������ͱ���
        file >> n >> m;

        Graph g(n);

        // ��ȡÿ�����Բ���ӱ�
        for (int i = 0; i < m; ++i) {
            int u, v;
            file >> u >> v;
            g.addEdge(u, v);
        }

        // ����ڵ�Ķ�������
        vector<int> degrees = g.degreeSequence();

        // ����ڵ�Ķ�������
        for (int degree : degrees) {
            cout << degree << " ";
        }
        cout << endl;
    }

    return 0;
}
