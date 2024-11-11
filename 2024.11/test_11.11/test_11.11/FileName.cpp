#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, t;
const int N = 25;
char mp[N][N];
bool vis[N][N][1 << 11];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

struct node {
    int x, y, key, Time;
    node() {};
    node(int u, int v, int z, int w)
        : x(u), y(v), key(z), Time(w) {};
};

queue<node> q;

int bfs(int stx, int sty) {
    int x, y, key;
    node now;
    q.push(node(stx, sty, 0, 0));
    vis[stx][sty][0] = true;

    while (!q.empty()) {
        now = q.front();
        q.pop();

        if (now.Time >= t)
            return -1;
        if (mp[now.x][now.y] == '^')
            return now.Time;

        for (int i = 0; i < 4; i++) {
            x = now.x + dir[i][0];
            y = now.y + dir[i][1];
            key = 0;

            if (x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1 && mp[x][y] != '*' && !vis[x][y][now.key]) {
                if (mp[x][y] >= 'a' && mp[x][y] <= 'j')
                    key |= (1 << (mp[x][y] - 'a'));
                else if (mp[x][y] >= 'A' && mp[x][y] <= 'J')
                    if (!(now.key & (1 << (mp[x][y] - 'A'))))
                        continue;

                q.push(node(x, y, now.key | key, now.Time + 1));
                vis[x][y][now.key] = true;
            }
        }
    }
    return -1;
}

int main() {
    int ans, stx, sty;
    while (cin >> n >> m >> t) {
        memset(vis, 0, sizeof(vis));
        while (!q.empty())
            q.pop();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mp[i][j];
                if (mp[i][j] == '@') {
                    stx = i;
                    sty = j;
                }
            }
        }
        ans = bfs(stx, sty);
        cout << ans << endl;
    }
    return 0;
}
