#include <iostream>
using namespace std;

int main()
{
	int a[10] = { 0 };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int b[10][10] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int tmp = i;
		for (int j = 0; j < n; j++)
		{
			b[i][j] = a[tmp++];
			tmp %= n;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << b[i][j] << " ";
		cout << endl;
	}

	return 0;
}