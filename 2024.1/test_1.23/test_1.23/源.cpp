#include <iostream>
using namespace std;

bool is_prime(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	/*int n;
	cin >> n;
	int tmp = 1;
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < tmp; i++)
		{
			cout << "*";
		}
		cout << endl;
		tmp++;
	}*/

	/*for (int i = 0; i <= 100 / 5; i++)
	{
		for (int j = 0; j <= 100 / 3; j++)
		{
			int k = 100 - i - j;
			if (k % 3 != 0)
				continue;
			if (i * 5 + j * 3 + k / 3 == 100)
				cout << i << " " << j << " " << k << endl;
		}
	}*/

	/*for (int i = 100; i <= 999; i++)
	{
		int a = i % 10;
		int b = (i / 10) % 10;
		int c = i / 100;

		if (i == a * a * a + b * b * b + c * c * c)
			cout << i << endl;
	}*/

	int a, b;
	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		if (is_prime(i))
			cout << i << endl;
	}

	return 0;
}