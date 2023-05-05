//#include <iostream>
//using namespace std;
//const int N = 110;
////Ç°×ººÍ
//int n;
//int a[N][N];
//int presum[N][N];
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			cin >> a[i][j], presum[i][j] = a[i][j] + presum[i][j - 1] + presum[i - 1][j] - presum[i - 1][j - 1];
//	int res = a[1][1];
//	for (int x1 = 1; x1 <= n; x1++)
//		for (int y1 = 1; y1 <= n; y1++)
//			for (int x2 = x1; x2 <= n; x2++)
//				for (int y2 = y1; y2 <= n; y2++)
//				{
//					int sum = presum[x2][y2] - presum[x1 - 1][y2] - presum[x2][y1 - 1] + presum[x1 - 1][y1 - 1];
//					res = max(sum, res);
//				}
//	cout << res << endl;
//	return 0;
//}