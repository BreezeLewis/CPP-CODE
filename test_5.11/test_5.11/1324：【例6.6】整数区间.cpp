//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 10010;
//struct node
//{
//	int begin, end;
//}a[N];
//int n;
//bool cmp(node x, node y)
//{
//	return x.end < y.end;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i].begin >> a[i].end;
//	sort(a + 1, a + n + 1, cmp);
//	int tmp = 1, res = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		if (a[tmp].end >= a[i].begin)
//			continue;
//		else
//			tmp = i, res++;
//	}
//	cout << res << endl;
//	return 0;
//}