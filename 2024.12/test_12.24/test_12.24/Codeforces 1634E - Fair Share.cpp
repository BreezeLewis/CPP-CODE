#include <iostream>
#include <vector>
#include <map>
#define maxn 300010
using namespace std;

int n, m, cnt;
map<int, int> mp;
vector<int> ans[maxn];
char s[maxn];

struct Edge {
    int to, next, x, y;
    bool ext;
} e[maxn * 2]; int c1, head[maxn], du[maxn];
inline void add_edge(int u, int v, int x, int y) {
    e[c1].to = v; e[c1].x = x; e[c1].y = y;
    e[c1].next = head[u]; head[u] = c1++;
}

void dfs(int u) {
    for (int& i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to, x = e[i].x, y = e[i].y; bool& ext = e[i].ext, & Ext = e[i ^ 1].ext;
        if (ext) continue; ext = Ext = 1; dfs(v);
        if (v <= n) ans[x][y] = 1;
    }
}

int main() {
    fill(head, head + maxn, -1);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int l, x; cin >> l; ans[i].resize(l);
        for (int j = 0; j < l; ++j) {
            cin >> x;
            if (!mp[x]) mp[x] = ++cnt;
            add_edge(i, mp[x] + n, i, j);
            add_edge(mp[x] + n, i, i, j);
            ++du[i]; ++du[mp[x] + n];
        }
    }
    for (int i = 1; i <= n + cnt; ++i) if (du[i] & 1) return cout << "NO" << "\n", 0;
    for (int i = 1; i <= n; ++i) dfs(i);
    cout << "YES" << "\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < ans[i].size(); ++j) s[j] = ans[i][j] ? 'L' : 'R';
        s[ans[i].size()] = 0; cout << s << "\n";
    }
    return 0;
}