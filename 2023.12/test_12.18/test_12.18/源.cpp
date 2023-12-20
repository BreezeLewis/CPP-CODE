#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

class Graph {
    int V; // �ڵ���
    vector<vector<int>> adj; // �ڽӱ�

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    // ��ӱ�
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // ��������
    vector<int> topologicalSort() {
        // ��¼�ڵ����
        vector<int> inDegree(V, 0);
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        // �����Ϊ 0 �Ľڵ�������
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);

            // �������ڽڵ����ȣ��������Ϊ 0 �Ľڵ�������
            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return result;
    }
};

int main() {
    int V, T, n;
    fstream file;
    file.open("D:\\cxdownload\\in2.txt", ios::in);
    file >> n;
    while (n--)
    {
        file >> V >> T;
        Graph g(V);

        while (T--)
        {
            int a, b;
            file >> a >> b;
            g.addEdge(a, b);
        }


        // ������������
        vector<int> result = g.topologicalSort();

        // ���������
        cout << "������������" << endl;
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    }
   
    
    
    

    

    

    return 0;
}
