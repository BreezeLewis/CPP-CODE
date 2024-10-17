#include <iostream>

using namespace std;

const int N = 1 << 10;

int board[N][N];
int cnt;

// sx,sy 表示区域的左上角坐标  顺序 左上 右上 左下 右下
void chessBoard(int sx, int sy, int x, int y, int size)
{
	if (size == 1) return;
	int s = size >> 1;
	int midx = sx + s - 1, midy = sy + s - 1; // 左上方块的右下坐标
	int num = ++cnt;

	if (x <= midx && y <= midy) // 左上
		chessBoard(sx, sy, x, y, s);
	else
	{
		board[midx][midy] = num;
		chessBoard(sx, sy, midx, midy, s);
	}

	if (x <= midx && y > midy) // 右上
		chessBoard(sx, sy + s, x, y, s);
	else
	{
		board[midx][midy + 1] = num;
		chessBoard(sx, sy + s, midx, midy + 1, s);
	}

	if (x > midx && y <= midy) // 左下
		chessBoard(sx + s, sy, x, y, s);
	else
	{
		board[midx + 1][midy] = num;
		chessBoard(sx + s, sy, midx + 1, midy, s);
	}

	if (x > midx && y > midy) // 右下
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