#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double Pi = 1;

	double ret = 1;

	double x = 1;

	int flag = 1;

	while (abs(x) > 1e-8)
	{
		ret += 2;

		x = 1 / ret;

		flag *= -1;

		x *= flag;

		Pi += x;
	}
	cout << 4 * Pi << endl;

	return 0;
}