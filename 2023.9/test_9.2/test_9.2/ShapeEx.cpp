#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	if (n % 2 == 0)//偶数行
	{
		for (int i = 1; i <= n / 2; i++)
		{
			for (int j = 1; j <= 2 * i - 1; j++)
				cout << '*';
			cout << endl;
		}
		for (int i = n / 2; i >= 1; i--)
		{
			for (int j = 1; j <= 2 * i - 1; j++)
				cout << '*';
			cout << endl;
		}
	}
	else//奇数行
	{
		for (int i = 1; i <= n / 2 + 1; i++)
		{
			for (int j = 1; j <= 2 * i - 1; j++)
				cout << '*';
			cout << endl;
		}
		for (int i = n / 2; i >= 1; i--)
		{
			for (int j = 1; j <= 2 * i - 1; j++)
				cout << '*';
			cout << endl;
		}
	}

	return 0;
}