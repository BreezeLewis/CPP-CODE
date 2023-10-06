#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;//输入线的个数
	int* height = new int[n];

	for (int i = 0; i < n; i++)
		cin >> height[i];//输入每条线的高度

	int maxx = 0;//储存答案

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int ret = height[i] > height[j] ? height[j] : height[i];
			maxx = max(maxx, (j - i)* ret);
		}
	}

	cout << maxx << endl;//输出结果

	return 0;
}