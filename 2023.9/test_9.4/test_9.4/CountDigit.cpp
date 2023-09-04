#include <iostream>
using namespace std;

void countDigit(long n, int a[])
{
	for (auto i = n; i /= 10; i)
	{
		a[n % 10]++;
	}
}
int main()
{

}