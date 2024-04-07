#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool vis[N];

void get_prime(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!vis[i]) primes[cnt++] = i;
		for (int j = 0; primes[j] <= n / i; j++)
		{
			vis[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

int main()
{
	int n;
	cin >> n;

	get_prime(n);

	cout << cnt << endl;

	return 0;
}