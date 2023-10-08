#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = i + 1;

	int size = n - 1;
	int idx = 0;
	while (size)
	{
		for (int i = 0; i < m; i++)
		{
			idx++; idx %= n;
			while (arr[idx] == 0)
				idx++, idx %= n;			
		}
		if (arr[idx])
			arr[idx] = 0;
		else
		{
			cout << "Òì³£·ÃÎÊ" << endl;
			return 1;
		}
		size--;
	}

	for (int i = 0; i < n; i++)
		if (arr[i])
			cout << "ºïÍõ±àºÅ" << i << endl;

}