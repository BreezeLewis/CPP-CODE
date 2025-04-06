#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// �ߵĽṹ��
struct Edge {
    int dest;       // Ŀ��ڵ�
    int weight;     // �ߵ�Ȩ��

    Edge(int d, int w) : dest(d), weight(w) {}
};

// �ȽϺ������������ȶ���
struct CompareDistance {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second; // С����
    }
};

class Graph {
private:
    int V;                          // ��������
    vector<vector<Edge>> adjList;   // �ڽӱ�

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    // ��ӱ�
    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back(Edge(dest, weight));
    }

    // Dijkstra�㷨ʵ��
    vector<int> dijkstra(int src) {
        // ��ʼ����������
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // ��¼�ڵ��Ƿ��Ѵ���
        vector<bool> processed(V, false);

        // ���ȶ��� <����, ����>
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareDistance> pq;
        pq.push(make_pair(src, 0));

        while (!pq.empty()) {
            // ��ȡ��ǰ������С�Ķ���
            int u = pq.top().first;
            pq.pop();

            // ����Ѵ���������
            if (processed[u]) continue;
            processed[u] = true;

            // ��������ھ�
            for (const Edge& edge : adjList[u]) {
                int v = edge.dest;
                int weight = edge.weight;

                // �ɳڲ���
                if (!processed[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(v, dist[v]));
                }
            }
        }

        return dist;
    }

    // ��ӡͼ
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "���� " << i << " ���ڽӱ�: ";
            for (const Edge& edge : adjList[i]) {
                cout << "(" << edge.dest << ", " << edge.weight << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    // ��������ͼ (5������)
    Graph g(5);

    // ��ӱ�
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);
    g.addEdge(1, 4, 7);

    cout << "ͼ���ڽӱ��ʾ:" << endl;
    g.printGraph();

    // �Ӷ���0����Dijkstra�㷨
    vector<int> distances = g.dijkstra(0);

    cout << "\n��Դ��0�����������̾���:" << endl;
    for (int i = 0; i < distances.size(); i++) {
        cout << "���� " << i << ": ";
        if (distances[i] == INT_MAX)
            cout << "���ɴ�";
        else
            cout << distances[i];
        cout << endl;
    }

    return 0;
}