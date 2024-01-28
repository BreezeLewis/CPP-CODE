#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main()
{
	/*int n;

	cin >> n;

	vector<int> v(n);

	cin >> v[0];

	int maxx = v[0], maxi = 0;

	for (int i = 1; i < n; i++)
	{
		cin >> v[i];
		if (v[i] > maxx)
			maxx = v[i], maxi = i;
	}

	cout << maxi + 1 << endl;*/

	int n;
	
	cin >> n;

	for (int i = 2; i <= n; i++)
		if (is_prime(i))
			cout << i << endl;

	return 0;
}