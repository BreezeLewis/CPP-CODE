//#include <iostream>
//using namespace std;
//// 1 0 0 0 1 0 0 1
//void f(int n, int bit)
//{
//	if (n == 0)
//		return;
//	int r = n % 2;//判断是否有余数
//	n /= 2;
//	f(n, bit + 1);
//	if (n && r)
//		cout << "+";
//	if (r)
//	{//可以分解最后一位的1
//		if (bit == 0)
//			cout << "2(0)";
//		else if (bit == 1)
//			cout << "2";
//		else if (bit == 2)
//			cout << "2(2)";
//		else
//		{
//			cout << "2(";
//			f(bit, 0);
//			cout << ")";
//		}
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	f(n, 0);
//	return 0;
//}