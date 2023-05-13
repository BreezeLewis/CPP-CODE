//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 110;
//int n;
//int vis[N];
//struct node
//{
//	int x, y;
//}a[N];
//bool cmp(node a, node b)
//{
//	if (a.x == b.x)
//		return a.y < b.y;
//	return a.x < b.x;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i].x >> a[i].y;
//	sort(a + 1, a + n + 1, cmp);
//	int miny = a[n].y;
//	vis[n] = 1;
//	for (int i = n - 1; i >= 1; i--)
//	{
//		if (a[i].y > miny)
//			vis[i] = 1, miny = a[i].y;
//	}
//	for (int i = 1; i <= n - 1; i++)
//		if (vis[i])
//			printf("(%d,%d),", a[i].x, a[i].y);
//	printf("(%d,%d)", a[n].x, a[n].y);
//	return 0;
//}