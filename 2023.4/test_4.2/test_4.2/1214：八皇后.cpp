//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int N = 8;
//vector<string> ans(100);
//int n = 1, a[20][20], vis1[20]/*�����*/, vis2[20]/*��Ǵ����ϵ����� i - j + n  */, vis3[20]/*��Ǵ����ϵ�����,״̬ѹ��i + j*/;
//
//void vis(int i, int j, int flag)
//{
//	a[i][j] = flag;
//	vis1[j] = flag;
//	vis2[i - j + N] = flag;
//	vis3[i + j] = flag;
//}
//
//string change()
//{
//	string ans;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			if (a[i][j])
//				ans += (j + '1');
//	return ans;
//}
//void dfs(int i)
//{
//	if (i == N)
//	{//�ݹ������������
//		ans[n++] = change();
//	}
//	for (int j = 0; j < N; j++)
//	{
//		if (!vis1[j] && !vis2[i - j + N] && !vis3[i + j])
//		{
//			vis(i, j, 1);
//			dfs(i + 1);
//			vis(i, j, 0);
//		}
//	}
//}
//int main()
//{
//	dfs(0);
//	int k, x;
//	cin >> k;
//	while (k--)
//	{
//		cin >> x;
//		cout << ans[x] << endl;
//	}
//	return 0;
//}