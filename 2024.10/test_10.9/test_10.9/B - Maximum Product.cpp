#include <iostream>

using namespace std;

int main()
{
	int n = 0, cnt = 0;

	while (cin >> n && n)
	{
		long long ans = 0;
		int num[100] = { 0 };

		for (int i = 0; i < n; i++) cin >> num[i];

		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
			{
				long long tmp = 1;
				for (int k = i; k <= j; k++) tmp *= num[k];

				if (tmp > ans) ans = tmp;
			}

		if (ans < 0) ans = 0;

		printf("Case #%d: The maximum product is %lld.\n\n", ++cnt, ans);
	}
}