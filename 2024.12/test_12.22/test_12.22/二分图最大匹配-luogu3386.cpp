#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1010;
using namespace std;

vector<int> edges[N];
int n, m, e;
int aim[N];
bool vis[N];

bool find(int x) {
    for (auto y : edges[x]) {
        if (!vis[y]) {
            vis[y] = true;
            if (aim[y] == 0 || find(aim[y])) {
                aim[y] = x;
                return true;
            }
        }
    }
    return false;
}

int match() {
    int ans = 0;
    memset(aim, 0, sizeof aim);
    for (int i = 1; i <= n; i++) {
        memset(vis, false, sizeof vis);
        if (find(i)) ans++;
    }
    return ans;
}

int main() {
    scanf("%d%d%d", &n, &m, &e);
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
    }
    cout << match() << endl;
    return 0;
}