#include <iostream>

using namespace std;

class Int
{
	int data = 0;
	static int num;
	static int isodd(int n);
public:
	Int(int n) //将n的值赋给data
	{
		this->data = n;
	}
	Int()
	{
		this->data = 0;
		(Int::num)++;
		printf("%d objects of Int has been constructed.",Int::num);
	}
	~Int()
	{
		(Int::num)--;
	}
	
};
int Int::isodd(int n)
{
	return n % 2 == 1;
}