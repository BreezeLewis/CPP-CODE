#include <iostream>
using namespace std;


//class A
//
//{
//
//public:
//
//  A() :m_iVal(0) { test(); }
//
//  virtual void func() { std::cout << m_iVal << ' '; }
//
//  void test() { func(); }
//
//public:
//
//  int m_iVal;
//
//};
//
//
//
//class B : public A
//
//{
//
//public:
//
//    B() { test(); }
//
//    virtual void func()
//
//    {
//
//        ++m_iVal;
//
//        std::cout << m_iVal << ' ';
//
//    }
//
//};
//
//
//
//int main()
//
//{
//
//    A* p = new B;
//
//    p->test();
//
//    return 0;
//
//}

class A

{

public:

    virtual void f()

    {

        cout << "A::f()" << endl;

    }

};



class B : public A

{

private:

    virtual void f()

    {

        cout << "B::f()" << endl;

    }

};



int main()
{
    A* pa = (A*)new B;

    pa->f();
    return 0;
}