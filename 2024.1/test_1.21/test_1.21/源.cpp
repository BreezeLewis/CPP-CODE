#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	/*int m, s = 0;
	cin >> m;
	int ans = 0;
	while (s <= m)
	{
		s += ans++;
	}

	cout << ans - 1;*/

	/*int m, n, min;
	cin >> m >> n;

	min = m < n ? m : n;

	for (int i = min; i >= 1; i--)
	{
		if (m % i == 0 && n % i == 0)
		{
			cout << i;
			break;
		}
	}*/

	
	//int m;
	//cin >> m;

	//double sum = 0;
	//int i = 0;
	//while (sum < m)
	//{
	//	i++;
	//	sum += 1.0 / i;	//
	//}

	//cout << i;

	vector<int> v;
	int x;
	int sum = 0;
	int minx = 1000, maxx = 0;
	while (cin >> x)
	{
		v.push_back(x);
		minx = min(minx, x);
		maxx = max(maxx, x);
		sum += x;
	}

	cout << minx << " " << maxx << " ";

	printf("%.3lf", sum / (double)v.size());
	
	return 0;
}

//
//#include<stdio.h>
//int main()
//{
//	int n = 0, min = 10000, max = -10000;
//	//���޶���Χ��������һ�¿���
//	int x;
//	double sum = 0, ave;
//	while (scanf("%d", &x) != -1)
//	{
//
//		if (x < min) { min = x; }
//		if (x > max) { max = x; }
//		sum += x;
//		n++;
//	}
//	ave = sum / (n);
//	printf("%d %d %.3lf", min, max, ave);
//	return 0;
//}
/*
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
	vector<int> nums;
	int num;

	// ��ȡ����ֱ����β
	while (cin >> num) {
		nums.push_back(num);
	}

	// ����Ƿ�������
	if (nums.empty()) {
		cout << "No numbers inputted." << endl;
		return 0;
	}

	int minVal = numeric_limits<int>::max();
	int maxVal = numeric_limits<int>::min();
	double sum = 0;

	// �������飬�������ֵ����Сֵ���ܺ�
	for (int n : nums) {
		minVal = min(minVal, n);
		maxVal = max(maxVal, n);
		sum += n;
	}

	// ����ƽ��ֵ
	double avg = sum / nums.size();

	// ������
	cout << minVal << " " << maxVal << " ";
	printf("%.3f\n", avg);

	return 0;
}
*/