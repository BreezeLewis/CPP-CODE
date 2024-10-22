#include <iostream>

using namespace std;

const int N = 110;

int a[N];

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];

	int avg = sum / n;
	int res = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == avg) continue;

		res++;
		int tmp = a[i] - avg;
		a[i] -= tmp;
		a[i + 1] += tmp;
	}

	cout << res << endl;
}