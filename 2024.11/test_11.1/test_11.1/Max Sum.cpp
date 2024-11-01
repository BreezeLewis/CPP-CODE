//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = (int)2e5 + 10;
//
//int a[N];
//
//int maxSum(int a[], int len)
//{
//	int res = a[0], curSum = a[0];
//
//	for (int i = 1; i < len; i++)
//	{
//		if (curSum < 0) curSum = a[i];
//		else curSum += a[i];
//
//		res = max(res, curSum);
//	}
//
//	return res;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++) cin >> a[i];
//
//	int res = maxSum(a, n);
//
//	cout << res << endl;
//
//	return 0;
//}



#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int)2e5 + 10;

int n, a[N];

int maxSum()
{
	int res = a[0], cur = a[0];

	for (int i = 1; i < n; i++)
	{
		if (cur < 0) cur = a[i];
		else cur += a[i];

		res = max(res, cur);
	}

	return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int res = maxSum();
	cout << res << endl;

	return 0;
}