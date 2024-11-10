#include <iostream>
#include <queue>
#define P pair<int, int>
using namespace std;

// ˫��BFS�㷨ʵ�֣���¼��ǰ״̬����ǰ��������ֵΪ1���Ӻ���ǰ����ֵΪ2
// ���ĳ״̬�£���ǰ�ڵ��׼����չ�ڵ��״̬���Ϊ3��˵������
queue<P> q1, q2;
int r, c, ans, dis[45][45], vst[45][45];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char m[45][45];

void dbfs() {
    bool flag;
    q1.push(P(1, 1)), dis[1][1] = 1, vst[1][1] = 1; // ��ǰ��
    q2.push(P(r, c)), dis[r][c] = 1, vst[r][c] = 2; // �Ӻ���
    while (!q1.empty() && !q2.empty()) {
        int x0, y0; // ÿ����չ������С�Ķ��� flag=1ǰ�ѣ�0����
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
                    if (vst[x0][y0] + vst[nx][ny] == 3) { // ����
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

