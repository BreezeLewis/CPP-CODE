#include <iostream>
#include <algorithm>

using namespace std;

int num[1010];

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++) num[i] = i;

		int tmp = 1;
		do
		{
			if (tmp == m)
				break;
			tmp++;
			
		} while (next_permutation(num + 1, num + n + 1));

		for (int i = 1; i <= n; i++) cout << num[i] << " ";
		cout << endl;
	}
}