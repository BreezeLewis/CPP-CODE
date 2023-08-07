//#include <iostream>
//using std::cout;
//using std::endl;
//class CBase
//{
//public:
//    virtual void FunTest1(int _iTest) {
//        cout << "CBase: : FunTest1() " << endl;
//    }
//    void FunTest2(int _iTest) {
//        cout << "CBase: : FunTest2() " << endl;
//    }
//    virtual void FunTest3(int _iTest1) {
//        cout << "CBase: : FunTest3() " << endl;
//    }
//    virtual void FunTest4(int _iTest) {
//        cout << "CBase: : FunTest4() " << endl;
//    }
//};
//class CDerived : public CBase
//{
//public:
//    virtual void FunTest1(int _iTest) {
//        cout << "CDerived: : FunTest1() " << endl;
//    }
//    virtual void FunTest2(int _iTest) {
//        cout << "CDerived: : FunTest2() " << endl;
//    }
//    void FunTest3(int _iTest1) {
//        cout << "CDerived: : FunTest3() " << endl;
//    }
//    virtual void FunTest4(int _iTest1, int _iTest2) {
//        cout << "CDerived: : FunTest4() " << endl;
//    }
//};
//int main() {
//    CBase* pBase = new CDerived;
//    pBase->FunTest1(0);
//    pBase->FunTest2(0);
//    pBase->FunTest3(0);
//    pBase->FunTest4(0);
//    delete pBase;
//    return 0;
//}
#include <iostream>
using namespace std;

class A
{
public:
    virtual void Print() { cout << "A::Print" << endl; }
};
class B : public A
{
public:
    void Print() { cout << "B::Print" << endl; }
};
class D : public A
{
public:
    void Print() { cout << "D::Print" << endl; }
};
class E : public B
{
    void Print() { cout << "E::Print" << endl; }
};

int main()
{
    A a; B b; E e; D d;

    A* pa = &a;
    B* pb = &b;
    D* pd = &d;
    E* pe = &e;

    pa->Print();

    pa = pb;
    pa->Print();

    pa = pd;
    pa->Print();

    pa = pe;
    pa->Print();

    return 0;
}