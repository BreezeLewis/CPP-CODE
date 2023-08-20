#include <iostream>
using namespace std;
class A 
{
public: 
	void test(float a) 
	{ 
		cout << a; 
	} 
}; 
class B :public A 
{ 
public: 
	void test(int b) 
	{ 
		cout << b; 
	} 
};

int main() 
{
	A* a = new A; 

	B* b = new B; 
	
	a = b; 
	
	a->test(1.1); 

	return 0;
}