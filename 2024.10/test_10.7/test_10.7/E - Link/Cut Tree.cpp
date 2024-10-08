#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll getAns(ll k, ll p)
{
	ll ans = 1;
	for (int i = 1; i <= p; i++) ans *= k;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);

	ll l, r, k, p;
	cin >> l >> r >> k;

	p = 0;
	bool legal = false;

	while (true)
	{
		if (pow(k, p) > r) break;
		if (pow(k, p) >= l && pow(k, p) <= r)
		{
			cout << getAns(k, p) << " ";
			legal = true;
		}
		p++;

	}

	if (legal == 0) cout << "-1" << endl;

	return 0;
}