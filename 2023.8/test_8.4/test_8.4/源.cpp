//#include <iostream>
//using namespace std;
//class A
//{
//public:
//    void virtual funPrint() { cout << "funPrint of class A" << endl; };
//};
//
//class B :public A
//{
//public:
//    void virtual funPrint() { cout << "funPrint of class B" << endl; };
//};
//
//int main()
//{
//    A* p;
//    A a;
//    B b;
//    p = &a;
//    p->funPrint();
//    p = &b;
//    p->funPrint();
//
//    return 0;
//}

#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "Construct A" << endl;
    }
};

class B : virtual public A
{
public:
    B() : A()
    {
        cout << "Construct B" << endl;
    }
public:

};

class C : virtual public A
{
public:
    C() :A()
    {
        cout << "Construct C" << endl;
    }
};

class D : public B, public C
{
public:
    D() : A(), B(), C()
    {
        cout << "Construct D" << endl;
    }

};
int main()
{
    D d;
    return 0;
}