#include <iostream>

using namespace std;

bool isLegal(int a, int b)
{
	int used[10] = { 0 };

	while (a)
	{
		used[a % 10]++;
		a /= 10;
	}

	while (b)
	{
		used[b % 10]++;
		b /= 10;
	}

	for (int i = 1; i < 10; i++)
		if (used[i] != 1) return false;

	return true;
}

int main()
{
	int n;
	int cnt = 0;
	while (cin >> n && n)
	{
		if (cnt++) cout << endl;

		int fghij = 1234;
		bool legal = false;

		while (n * fghij <= 98765)
		{
			if (isLegal(n * fghij, fghij))
			{
				legal = true;
				printf("%05d / %05d = %d\n", fghij * n, fghij, n);
			}
			fghij++;
		}

		if (legal == false) printf("There are no solutions for %d.\n", n);
	}

	return 0;
}