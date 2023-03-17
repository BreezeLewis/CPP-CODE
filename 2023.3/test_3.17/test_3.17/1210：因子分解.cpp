//#include<iostream>
//using namespace std;
//bool flag = false;
//
//void f(int n, int div, int dep)
//{
//	if (n == 1)
//	{
//		if (flag)
//			cout << "*";
//		//flag = true;
//		if (dep >= 2)
//			cout << div << "^" << dep;
//		else
//			cout << div;
//		return;
//	}
//	if (n % div == 0)
//		f(n / div, div, dep + 1);
//	else
//	{
//		if (dep > 0)
//		{
//			if (flag)
//				cout << "*";
//			flag = true;
//			if (dep >= 2)
//				cout << div << "^" << dep;
//			else
//				cout << div;
//		}
//		f(n, div + 1, 0);
//	}
//}
//int main() 
//{
//	/*int n;
//	cin >> n;*/
//	int n = 180;
//	f(n, 2, 0);
//
//	return 0;
//}