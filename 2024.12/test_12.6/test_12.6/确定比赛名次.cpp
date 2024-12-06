#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

const int MAXN = 500;
vector<int> edge[MAXN];
int n, m;
int res[MAXN], degree[MAXN];
priority_queue<int, vector<int>, greater<int> > que;

int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < MAXN; i++) {
            edge[i].clear();
        }
        int u, v;
        while (m--) {
            cin >> u >> v;
            edge[u].push_back(v);
            degree[v]++;
        }
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 0) {
                que.push(i);
            }
        }
        int rear = 0;
        while (!que.empty()) {
            int x = que.top();
            que.pop();
            res[++rear] = x;
            for (int y : edge[x]) {
                if (--degree[y] == 0) {
                    que.push(y);
                }
            }
        }
        cout << res[1];
        for (int i = 2; i <= n; i++) {
            cout << " " << res[i];
        }
        cout << endl;
    }
    return 0;
}