#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int water[N];

int main()
{
	int T;	
	cin >> T;
	while (T--)
	{
		int n, V, W;
		cin >> n >> V >> W;
		int water[N] = { 0 };
		for (int i = 0; i < n; i++) cin >> water[i];

		sort(water, water + n);

		int sum_v = 0; double sum_n = 0;

		for (int i = 0; i < n; i++)
		{
			sum_v += V;
			sum_n += water[i] * V;
			if (sum_n / sum_v > W)
			{
				sum_v -= V;
				sum_n -= water[i] * V;
				break;
			}
		}

		if (sum_v == 0) printf("0 0.00\n");
		else printf("%d %.2lf\n", sum_v, sum_n / sum_v / 100.0);
	}
}