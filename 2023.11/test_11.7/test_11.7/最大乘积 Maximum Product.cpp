#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
ll a[100];
int main()
{
	int num = 0;
	while (cin >> n)
	{
		ll ans = 0;
		
		for (int i = 0; i < n; i++)
			cin >> a[i];
		
		for (int i = 0; i < n; i++)
		{
			ll tmp = 1;
			for (int j = i; j < n; j++)
			{
				tmp *= a[j];
				ans = max(ans, tmp);
			}
		}

		if (ans < 0)
			ans = 0;
		printf("Case #%d: The maximum product is %lld.\n\n", ++num, ans);
		
	}

	return 0;
}
