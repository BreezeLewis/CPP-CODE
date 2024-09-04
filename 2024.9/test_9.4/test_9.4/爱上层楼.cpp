#include <iostream>

using namespace std;

typedef long long ll;

ll n, m;

int T;

int countLastDigit(ll n, ll m)
{
	if (m == 0) return 1;

	n = n % 10;

	int cycle[4];
	cycle[0] = n;
	for (int i = 1; i < 4; i++)
		cycle[i] = (cycle[i - 1] * n) % 10;

	int pos = (m - 1) % 4;

	return cycle[pos];
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		cout << countLastDigit(n, m) << endl;
	}

	return 0;
}