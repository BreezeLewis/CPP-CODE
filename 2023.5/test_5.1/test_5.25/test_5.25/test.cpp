//////#include<iostream>
//////using namespace std;
//////class X
//////{
//////    int m;
//////public:
//////    X() : m(10) {}
//////    X(int mm) : m(mm) {}
//////    int getm()
//////    {
//////        return m;
//////    }
//////};
//////class Y : public X
//////{
//////    int n;
//////public:
//////    Y(int nn) : n(nn) {}
//////    int getn() { return n; }
//////};
//////int main()
//////{
//////    Y yobj(100);
//////    cout << yobj.getm() << " " << yobj.getn() << endl;
//////}
////
////#include<iostream>
////using namespace std;
////class BASE {
////public:
////	int mem1;
////	BASE() {
////		mem1 = 1;
////		cout << "BASE()" << endl;
////	}
////	BASE(int x) {
////		mem1 = x;
////		cout << "BASE(int)" << endl;
////	}
////};
////class DERIVED : public BASE {
////public:
////	int mem2;
////	BASE mem3;
////	DERIVED() : mem2(2), mem3(3) {
////		cout << "DERIVED()" << endl;
////	}
////};
////int main()
////{
////	DERIVED t;
////}
//
//#include<iostream>
//using namespace std;
//class A {
//public:
//    void f()
//    {
//        cout << "A" << endl;
//    }
//
//};
//
//class B : public A {
//public:
//    void f(int a)
//    {
//        cout << "B" << endl;
//    }
//};
//
//int main()
//{
//    B b;
//    b.f(10);
//}


#include <iostream>
using namespace std;
int main()
{
	double d = 12.34;
	const int& ret = d;

	cout << (int)12.34 << endl;

	cout << ret << endl;
	cout << ret << endl;
	cout << ret << endl;

	return 0;
}