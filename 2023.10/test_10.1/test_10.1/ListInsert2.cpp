#include <iostream>

using namespace std;

void insertData(int a[], int n, int x)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (x >= a[i])
		{
			//Å²¶¯Êı¾İ
			for (int j = n - 1; j > i; j--)
			{
				a[j + 1] = a[j];
			}
			a[i + 1] = x;
			break;
		}
	}
}
int main()
{
	int a[10] = { 1,3,5,7,9,11,30,50 };
	int n = 8;
	int x = 10;

	insertData(a, n, x);

	for (int i = 0; i < 9; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}