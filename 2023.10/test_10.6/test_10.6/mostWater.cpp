#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;//�����ߵĸ���
	int* height = new int[n];

	for (int i = 0; i < n; i++)
		cin >> height[i];//����ÿ���ߵĸ߶�

	int maxx = 0;//�����

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int ret = height[i] > height[j] ? height[j] : height[i];
			maxx = max(maxx, (j - i)* ret);
		}
	}

	cout << maxx << endl;//������

	return 0;
}