#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int weight = 1;
	int ans = 0;
	for (int i = n; i; i /= 10)
	{
		int ret = i % 10;
		ans += ret * weight;
		weight *= 8;
	}
	cout << ans << endl;
	return 0;
}