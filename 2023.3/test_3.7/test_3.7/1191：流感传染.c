#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int vis[110][110];
//char a[110][110];
//int n, m, res;
//int dx[] = { 1,-1,0,0 };
//int dy[] = { 0,0,1,-1 };
//int main()
//{
//	scanf("%d", &n);
//	getchar();
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = 1;j <= n;j++)
//			scanf("%c", &a[i][j]);
//		getchar();
//	}
//	scanf("%d", &m);
//	//  . ��ʾ��������   
//	//  # ��ʾ����Ϊ��
//	//  @ ��ʾ�����е���  ���ڵ���Ϊ . �򱻸�Ⱦ
//	while (--m)
//	{
//		for (int i = 1;i <= n;i++)
//			for (int j = 1;j <= n;j++)
//				if (a[i][j] == '@')
//				{
//					for (int k = 0;k < 4;k++)
//					{
//						int bx = dx[k] + i;
//						int by = dy[k] + j;
//						//�ж�Խ��
//						if (bx<1 || bx >n || by<1 || by>n)
//							continue;
//						//����ǽ������˾ͱ��
//						if (a[bx][by] == '.')
//							vis[bx][by] = 1;
//					}
//				}
//		for (int i = 1;i <= n;i++)
//			for (int j = 1;j <= n;j++)
//				if (vis[i][j])
//					a[i][j] = '@';
//
//	}
//	for (int i = 1;i <= n;i++)
//		for (int j = 1;j <= n;j++)
//			if (a[i][j] == '@')
//				res++;
//	printf("%d\n", res);
//	return 0;
//}