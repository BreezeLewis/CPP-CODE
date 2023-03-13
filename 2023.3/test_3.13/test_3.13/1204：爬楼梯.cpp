#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int n, a[31];
int f(int n)
{
	if (n <= 3)
		return n;
	return f(n - 1) + f(n - 2);
}
int main()
{
	while (cin >> n)
	{
		cout << f(n) << endl;
	}
	return 0;
}