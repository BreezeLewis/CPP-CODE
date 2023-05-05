//#include <iostream>
//using namespace std;
//int count_one(int n)
//{
//	int res = 0;
//	for (int i = n; i; i /= 2)
//	{
//		if (i % 2 == 1)
//			res++;
//	}
//	return res;
//}
//int main()
//{
//	int n = 0;
//	while (cin >> n && n)
//	{
//		int ret = count_one(n);
//		for (int i = n + 1;; i++)
//		{
//			if (ret == count_one(i))
//			{
//				cout << i << endl;
//				break;
//			}
//		}
//	}
//	return 0;
//}