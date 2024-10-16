#include<iostream>
using namespace std;
int board[1000][1000];
int num = 0;

void chessBoard(int c, int r, int x, int y, int size) {
    if (size == 1) return;
    int cnt = ++num;
    int s = size / 2;
    int midx = c + s - 1; // �������̵������½�x����
    int midy = r + s - 1; // �������̵������½�y����

    if (x <= midx && y <= midy) // ���ⷽ��������
        chessBoard(c, r, x, y, s);
    else { // ��������û�����ⷽ��
        board[midx][midy] = cnt;
        chessBoard(c, r, midx, midy, s);
    }

    if (x <= midx && y > midy) // ���ⷽ��������
        chessBoard(c, r + s, x, y, s);
    else {
        board[midx][midy + 1] = cnt;
        chessBoard(c, r + s, midx, midy + 1, s);
    }

    if (x > midx && y <= midy) // ���ⷽ��������
        chessBoard(c + s, r, x, y, s);
    else {
        board[midx + 1][midy] = cnt;
        chessBoard(c + s, r, midx + 1, midy, s);
    }

    if (x > midx && y > midy) // ���ⷽ��������
        chessBoard(c + s, r + s, x, y, s);
    else {
        board[midx + 1][midy + 1] = cnt;
        chessBoard(c + s, r + s, midx + 1, midy + 1, s);
    }
}

int main() {
    int k, x, y;
    cin >> k >> x >> y;
    board[x][y] = 0;
    chessBoard(1, 1, x, y, (1 << k));
    for (int i = 1; i <= (1 << k); i++) {
        for (int j = 1; j <= (1 << k); j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}
