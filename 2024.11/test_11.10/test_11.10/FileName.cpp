#include <iostream>
#include <queue>
#define P pair<int, int>
using namespace std;

// 双向BFS算法实现，记录当前状态、从前往后搜索值为1，从后往前搜索值为2
// 如果某状态下，当前节点和准备扩展节点的状态相加为3，说明相遇
queue<P> q1, q2;
int r, c, ans, dis[45][45], vst[45][45];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char m[45][45];

void dbfs() {
    bool flag;
    q1.push(P(1, 1)), dis[1][1] = 1, vst[1][1] = 1; // 从前搜
    q2.push(P(r, c)), dis[r][c] = 1, vst[r][c] = 2; // 从后搜
    while (!q1.empty() && !q2.empty()) {
        int x0, y0; // 每次扩展搜索树小的队列 flag=1前搜，0后搜
        if (q1.size() > q2.size()) {
            x0 = q2.front().first, y0 = q2.front().second;
            q2.pop();
            flag = 0;
        }
        else {
            x0 = q1.front().first, y0 = q1.front().second;
            q1.pop();
            flag = 1;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x0 + dx[i], ny = y0 + dy[i];
            if (nx >= 1 && nx <= r && ny >= 1 && ny <= c && m[nx][ny] == '.') {
                if (!dis[nx][ny]) {
                    dis[nx][ny] = dis[x0][y0] + 1;
                    vst[nx][ny] = vst[x0][y0];
                    if (flag) q1.push(P(nx, ny));
                    else q2.push(P(nx, ny));
                }
                else {
                    if (vst[x0][y0] + vst[nx][ny] == 3) { // 相遇
                        ans = dis[nx][ny] + dis[x0][y0];
                        return;
                    }
                }
            }
        }
    }
}


int main() {
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> m[i][j];

    dbfs();

    cout << ans << "\n";
    return 0;
}

