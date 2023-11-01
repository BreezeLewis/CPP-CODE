#include <stdio.h>
#include <vector>
#include <windows.h>
#include <time.h>
#include <math.h> 
using namespace std;

struct POS
{
	int row, col;
};
int Find_neighbor_cell(POS cur_pos, bool board[7][7], vector <POS> &neighbor_cell);  // 找到同色下一个可选位置 
int Compute_distance(POS A, POS B);  // 计算是否相遇 
void printMap(POS A, POS B, bool board[7][7]);  // 输出棋盘 
int count=0;  // 步数 
int main()
{
	bool board[7][7] = { {0,1,0,1,0,1,0},     // 定义棋盘数据 
						 {1,0,1,0,1,0,1},
						 {0,1,0,1,0,1,0},
						 {1,0,1,0,1,0,1},
						 {0,1,0,1,0,1,0},
						 {1,0,1,0,1,0,1},
						 {0,1,0,1,0,1,0} };

	srand(time(NULL));

	//
	POS A, B;
	A.row = 0;
	A.col = 0;
	B.row = 5;
	B.col = 6;
	while (Compute_distance(A, B) > 1) 
	{
		vector <POS> A_neighbor, B_neighbor;
		Find_neighbor_cell(A, board, A_neighbor); 
		Find_neighbor_cell(B, board, B_neighbor);

		int AID, BID;
		AID = rand() % A_neighbor.size(); // 随机的同色下一个位置 
		BID = rand() % B_neighbor.size();

		A = A_neighbor[AID];
		B = B_neighbor[BID];

		printMap(A, B, board); 
	}

	return 1;
}

int Find_neighbor_cell(POS cur_pos, bool board[7][7], vector <POS> &neighbor_cell)
{
	int row = cur_pos.row;
	int col = cur_pos.col;
	int cur_value = board[row][col];

	int srow, erow;
	int scol, ecol;
	srow = row - 1;
	scol = col - 1;
	erow = row + 1;
	ecol = col + 1;
	if (srow < 0) srow = 0;
	if (scol < 0) scol = 0;
	if (erow > 6) erow = 6;
	if (ecol > 6) ecol = 6;
	for (int trow = srow; trow<=erow; trow++)
		for (int tcol = scol; tcol <= ecol; tcol++)
		{
			if (tcol == col && trow == row) continue;

			if (board[trow][tcol] == cur_value)
			{
				POS temp;
				temp.row = trow;
				temp.col = tcol;
				neighbor_cell.push_back(temp);
			}
		}

	if (neighbor_cell.size() == 0) return 0;
	return 1;
}

int Compute_distance(POS A, POS B)
{
	float dis = sqrt((A.row - B.row)*(A.row - B.row) + (A.col - B.col)*(A.col - B.col));

	return (int)(dis + 0.5);
}

void printMap(POS A, POS B, bool board[7][7])
{   count ++;
	printf("\nstep: %d\n\n", count);

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (i == A.row && j == A.col)
				printf(" A");
			else if (i == B.row && j == B.col)
				printf(" B");
			else if(i%2 == 0 && j%2 == 1 || i%2 == 1 && j%2 == 0)
				printf(" #");
			else
			    printf(" 0");
		}
		printf("\n");
	}

	Sleep(3000);
}

