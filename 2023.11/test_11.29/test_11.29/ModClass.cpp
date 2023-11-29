//21310386 卢昀生

#include <iostream>
#include <cstdlib>
using namespace std;

class ModClass
{
	friend ModClass operator*(const ModClass& x, const ModClass& y);
	
private:
	int dataval;
public:
	ModClass(int v = 0)
	{
		dataval = v % 7;
	}
	ModClass operator + (const ModClass& x)
	{
		return ModClass((this->dataval + x.dataval) % 7);
	}
	int GetValue()
	{
		return dataval;
	}
	operator int()
	{
		return this->dataval;
	}
	ModClass operator=(const ModClass& m)
	{
		this->dataval = m.dataval;
		return *this;
	}
};

ModClass operator* (const ModClass& x, const ModClass& y)
{
	return ModClass((x.dataval * y.dataval) % 7);
}

ModClass Inverse(ModClass& x)
{
	if (x.GetValue() == 0)
	{
		cout << "形参x的dataval只能取非0值！！！" << endl;
		exit(-1);
	}
	for (int i = 1; i <= 6; i++)
	{
		ModClass y(i);
		if ((y * x).GetValue() == 1)
			return y;
	}
}

void Solve(ModClass a, ModClass& x, ModClass b)
{
	for (int i = 0; i <= 6; i++)
	{
		ModClass tmp(i);
		if ((a * tmp).GetValue() == b.GetValue())
		{
			x = tmp;
			return;
		}
	}
}
//
//int main()
//{
//	ModClass a(10), b(6), c;
//	c = a + b;
//	cout << (int)c << endl; //(3 + 6) / 7 = 2
//
//	printf("%d * %d = %d\n", (int)a, (int)b, (int)(a * b));
//
//	printf("Inverse(a) = %d\n", (int)Inverse(a));
//	printf("Inverse(b) = %d\n", (int)Inverse(b));
//	printf("Inverse(c) = %d\n", (int)Inverse(c));
//
//
//	ModClass d(4), e(2), x;
//	Solve(d, x, e);
//	cout << x << endl;
//
//	return 0;
//}


int main()
{
	char tmp[16];
	char ret[8];
	cout << sizeof(tmp) << " " << sizeof(ret) << endl;

	char num[256];
	cout << sizeof(num) << endl;
	return 0;
}