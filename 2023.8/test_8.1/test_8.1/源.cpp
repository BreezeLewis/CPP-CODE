#include <iostream>
using namespace std;
class A

{

public:

  void f1() { cout << "A::f1()" << endl; }

  virtual void f2() { cout << "A::f2()" << endl; }

  virtual void f3() { cout << "A::f3()" << endl; }

};



class B : public A

{

public:

	virtual void f1() { cout << "B::f1()" << endl; }

	virtual void f2() { cout << "B::f2()" << endl; }

	void f3() { cout << "B::f3()" << endl; }

};
int main()
{

	return 0;
}