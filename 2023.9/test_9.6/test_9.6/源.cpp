//////#include <iostream>
//////using namespace std;
//////int main()
//////{
//////	int a, b;
//////	scanf("%d%d", &a, &b);
//////
//////	printf("%d", a + b);
//////
//////	return 0;
//////}
////
////#include <iostream>
////using namespace std;
////int main()
////{
////	char ch;
////	cin >> ch;
////
////	cout << "  " << ch;
////	cout << endl;
////	cout << " ";
////	for (int i = 0; i < 3; i++)
////		cout << ch;
////	cout << endl;
////	for (int i = 0; i < 5; i++)
////		cout << ch;
////	cout << endl;
////
////
////	return 0;
////}
//
////#include <iostream>
////using namespace std;
////int main()
////{
////	int a, b;
////	scanf("%d%d", &a, &b);
////
////	printf("%d", a + b);
////
////	return 0;
////}
//
//#include <iostream>
//using namespace std;
//int main()
//{
//	double r;
//	cin >> r;
//
//	double pi = 3.14159;
//
//	printf("%.4lf %.4lf %.4lf", 2 * r, 2 * pi * r, pi * r * r);
//
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int fib[50];
//	fib[1] = fib[2] = 1;
//	for (int i = 3; i <= 40; i++)
//		fib[i] = fib[i - 1] + fib[i - 2];
//
//	int n, x;
//	cin >> n;
//	while (n--)
//	{
//		cin >> x;
//		cout << fib[x] << endl;
//	}
//
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a, b, c;
//	cin >> a >> b >> c;
//	cout << b << endl;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int N, maxx = -10000000;
//	int a[1000];
//	int ans = 0;
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> a[i];
//		if (a[i] > maxx)
//			maxx = a[i];
//	}
//
//	for (int i = 0; i < N; i++)
//		if (a[i] == maxx)
//			continue;
//		else
//			ans += a[i];
//
//	cout << ans << endl;
//	return 0;
//}

#include <iostream>
using namespace std;

int main()
{
	int a[200][200];
	int r, c;
	int ans = 0;
	cin >> r >> c;

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
		{
			cin >> a[i][j];
			if (i == 1 || i == r || j == 1 || j == c)
				ans += a[i][j];
		}

	cout << ans << endl;
	
	return 0;
}