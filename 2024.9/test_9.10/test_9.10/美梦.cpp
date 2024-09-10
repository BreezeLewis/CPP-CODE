#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

string target = "123456780";

// ������ת��Ϊ�ַ���
string boardToString(vector<vector<int>>& board) {
    string s = "";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            s += to_string(board[i][j]);
        }
    }
    return s;
}

// ��ȡ0��λ��
pair<int, int> getZeroPosition(string& s) {
    int index = s.find('0');
    return { index / 3, index % 3 };
}

// �ж��Ƿ���Խ���λ��
bool isValid(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

// ����Ŀ��״̬�Ƿ����ͨ����������
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
