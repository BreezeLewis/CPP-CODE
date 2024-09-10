#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

string target = "123456780";

// 将棋盘转换为字符串
string boardToString(vector<vector<int>>& board) {
    string s = "";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            s += to_string(board[i][j]);
        }
    }
    return s;
}

// 获取0的位置
pair<int, int> getZeroPosition(string& s) {
    int index = s.find('0');
    return { index / 3, index % 3 };
}

// 判断是否可以交换位置
bool isValid(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

// 计算目标状态是否可以通过滑动到达
bool canSolve(vector<vector<int>>& board) {
    string start = boardToString(board);
    if (start == target) return true;

    vector<pair<int, int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    unordered_set<string> visited;
    queue<string> q;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        pair<int, int> zeroPos = getZeroPosition(current);
        int x = zeroPos.first, y = zeroPos.second;

        for (auto dir : directions) {
            int newX = x + dir.first, newY = y + dir.second;
            if (isValid(newX, newY)) {
                string next = current;
                swap(next[x * 3 + y], next[newX * 3 + newY]);
                if (next == target) return true;
                if (visited.find(next) == visited.end()) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<vector<int>> board(3, vector<int>(3));
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> board[i][j];
            }
        }
        if (canSolve(board)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}
