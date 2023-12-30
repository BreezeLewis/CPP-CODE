#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
    vector<int> root, rank;

public:
    UnionFind(int size) : root(size), rank(size) {
        for (int i = 0; i < size; ++i) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            }
            else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int kruskal(int n, vector<tuple<int, int, int>>& edges) {
    sort(edges.begin(), edges.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<2>(a) < get<2>(b);
        });

    UnionFind uf(n);
    int totalWeight = 0;

    for (const auto& [u, v, weight] : edges) {
        if (!uf.connected(u, v)) {
            uf.unionSet(u, v);
            totalWeight += weight;
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;

    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges.emplace_back(u - 1, v - 1, w);
    }

    cout << "Minimum Spanning Tree Weight: " << kruskal(n, edges) << endl;

    return 0;
}
