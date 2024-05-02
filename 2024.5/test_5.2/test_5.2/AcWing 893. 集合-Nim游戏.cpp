#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

const int N = 110, M = 10010;

int n, m;
int s[N], f[M];

int sg(int x)
{
	if (f[x] != -1) return f[x];

	unordered_set<int> S;
	for (int i = 0; i < m; i++)
		if (x >= s[i]) S.insert(sg(x - s[i]));

	for (int i = 0; ; i++)
		if (!S.count(i))
			return f[x] = i;
}

int main()
{
	cin >> m;
	for (int i = 0; i < m; i++) cin >> s[i];

	memset(f, -1, sizeof f);

	cin >> n;
	int res = 0;
	while (n--)
	{
		int x;
		cin >> x;
		res ^= sg(x);
	}

	if (res) puts("Yes");
	else puts("No");

	return 0;
}