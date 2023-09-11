#include <iostream>
#include <string>
using namespace std;

bool is_prime(int x)
{
	if (x <= 1)
		return false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}
int main()
{
	int n = 2;

	if (is_prime(n))
	{
		cout << n << "=" << n << endl;
		return 0;
	}


	//cin >> n;
	string ans;
	int i;
	for (i = n; is_prime(i) == false;)
		for(int j = 2;j*j<=i;j++)
			if (i % j == 0)
			{
				ans += j + '0';
				ans += '*';
				i /= j;
				break;
			}
	ans += i + '0';
	

	cout << n << "=" << ans << endl;

	return 0;
}