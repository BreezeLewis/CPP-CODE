#include <iostream>
using namespace std;

int main()
{
	/*int n;
	cin >> n;
	const int num = 1992;

	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		ans = ans * num % 100;
	}

	cout << ans << endl;*/

	/*for (int i = 1; i; i++)
	{
		if (i % 2 == 1 && i % 3 == 1 && i % 4 == 1 && i % 5 == 1 && i % 6 == 1 && i % 7 == 0)
		{
			cout << i << endl;
			break;
		}
	}*/

	int n, sum = 0, tmp = 1;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		tmp *= i;
		sum += tmp;
	}

	cout << sum << endl;

	return 0;
}