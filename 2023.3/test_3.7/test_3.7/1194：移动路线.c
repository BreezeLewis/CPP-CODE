#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int row, col;
//int a[50][50];
//int main()
//{
//	scanf("%d%d", &row, &col);
//	for (int i = 1;i <= row;i++)
//		for (int j = 1;j <= col;j++)
//			if (i == 1 || j == 1)
//				a[i][j] = 1;
//	for (int i = 2;i <= row;i++)
//		for (int j = 2;j <= col;j++)
//			a[i][j] = a[i - 1][j] + a[i][j - 1];
//
//	printf("%d\n", a[row][col]);
//	return 0;
//}