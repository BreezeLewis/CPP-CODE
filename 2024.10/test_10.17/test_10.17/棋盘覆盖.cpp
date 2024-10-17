#include <iostream>

using namespace std;

const int N = 1 << 10;

int board[N][N];
int cnt;

// sx,sy ��ʾ��������Ͻ�����  ˳�� ���� ���� ���� ����
void chessBoard(int sx, int sy, int x, int y, int size)
{
	if (size == 1) return;
	int s = size >> 1;
	int midx = sx + s - 1, midy = sy + s - 1; // ���Ϸ������������
	int num = ++cnt;

	if (x <= midx && y <= midy) // ����
		chessBoard(sx, sy, x, y, s);
	else
	{
		board[midx][midy] = num;
		chessBoard(sx, sy, midx, midy, s);
	}

	if (x <= midx && y > midy) // ����
		chessBoard(sx, sy + s, x, y, s);
	else
	{
		board[midx][midy + 1] = num;
		chessBoard(sx, sy + s, midx, midy + 1, s);
	}

	if (x > midx && y <= midy) // ����
		chessBoard(sx + s, sy, x, y, s);
	else
	{
		board[midx + 1][midy] = num;
		chessBoard(sx + s, sy, midx + 1, midy, s);
	}

	if (x > midx && y > midy) // ����
		chessBoard(sx + s, sy + s, x, y, s);
	else
	{
		board[midx + 1][midy + 1] = num;
		chessBoard(sx + s, sy + s, midx + 1, midy + 1, s);
	}

}

int main()
{
	int k, x, y;
	cin >> k >> x >> y;

	chessBoard(0, 0, x - 1, y - 1, 1 << k);

	for (int i = 0; i < 1 << k; i++)
	{
		for (int j = 0; j < 1 << k; j++) cout << board[i][j] << ' ';
		cout << endl;
	}
}