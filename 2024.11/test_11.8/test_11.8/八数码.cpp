#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
string d = "durl";
int lys = 11;

struct node {
    string state;
    int cantor;
    int pos; // x position
    node(string s, int c, int pp) : state(s), cantor(c), pos(pp) {}
};

struct path { // Structure for quick state lookup
    int from; // Previous state Cantor value
    char dir; // Direction from previous state
} pa[362888];

bool legal(int x, int y) {
    if (x >= 0 && x <= 2 && y >= 0 && y <= 2)
        return true;
    return false;
}

int visited[362888] = { 0 };
int factory[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

int getCantor(string str) {
    int res = 0;
    for (int i = 0; i < 9; i++) {
        int cnt = 0;
        for (int j = i + 1; j < 9; j++) {
            if (str[i] > str[j])
                cnt++;
        }
        res += cnt * factory[9 - i - 1];
    }
    return res;
}


void bfs(string init) {
    queue<node> que;
    int num = getCantor(init);
    que.push(node(init, num, 8));
    visited[num] = 1;
    pa[num].from = -1;
    while (!que.empty()) {
        node top = que.front();
        que.pop();
        int x = top.pos / 3;
        int y = top.pos % 3;
        for (int i = 0; i < 4; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (!legal(xx, yy))
                continue;
            int move = 3 * xx + yy;
            string next_state = top.state;
            swap(next_state[top.pos], next_state[move]);
            num = getCantor(next_state);
            if (visited[num])
                continue;
            visited[num] = 1;
            que.push(node(next_state, num, move));
            pa[num].from = top.cantor;
            pa[num].dir = d[i];
        }
    }
}

int main() {
    bfs("12345678x");
    string tmp;
    while (getline(cin, tmp)) {
        string puzzle;
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] != ' ') {
                puzzle.push_back(tmp[i]);
            }
        }
        int num = getCantor(puzzle);
        if (visited[num] == 0) {
            cout << "unsolvable" << endl;
            continue;
        }
        while (true) {
            if (pa[num].from == -1)
                break;
            cout << pa[num].dir;
            num = pa[num].from;
        }
        cout << endl;
    }
    return 0;
}
