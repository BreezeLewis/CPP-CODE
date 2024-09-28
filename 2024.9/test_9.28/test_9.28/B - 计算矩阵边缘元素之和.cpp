#include <iostream>

using namespace std;

const int N = 110;

int a[N][N], ans = 0;

int main()
{
	int m, n;
	cin >> m >> n;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j], ans += a[i][j];

	for (int i = 1; i < m - 1; i++)
		for (int j = 1; j < n - 1; j++)
			ans -= a[i][j];

	cout << ans << endl;

	return 0;
}