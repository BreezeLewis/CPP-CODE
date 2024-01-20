#include <iostream>
using namespace std;

int main()
{
	/*int x;
	cin >> x;
	int maxi = 0, maxj = 0, maxk = 0;
	int maxx = 0;
	for(int i = 0; i <= x / 6; i++)
		for (int j = 0; j <= x / 5; j++)
		{
			int left = x - i * 6 - j * 5;
			if (left % 4 == 0)
			{
				if (i + j + left / 4 > maxx)
				{
					maxx = i + j + left / 4;
					maxi = i, maxj = j, maxk = left / 4;
				}
			}
		}

	cout << maxi << " " << maxj << " " << maxk;*/

	/*int n, sum = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
		sum += i;

	cout << sum << endl;*/

	/*int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
			cout << i << " ";
	}*/

	/*int n;
	cin >> n;
	int sum1 = 0, sum2 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
			sum1 += i;
		else
			sum2 += i;
	}

	cout << sum1 << " " << sum2;*/

	int n; 
	cin >> n;

	long long sum = 1;
	for (int i = 2; i <= n; i++)
	{
		sum *= i;
	}
	cout << sum;

	return 0;
}