//////////#include <iostream>       
//////////using namespace std;
//////////
//////////class EBase {
//////////    //EX1：添加 virtual 比较输出不同 
//////////public: void what() { cout << "base" << endl; };
//////////};
//////////
//////////class EDrived :public EBase {
//////////public: void what() { cout << "EDrived" << endl; };
//////////};
//////////
//////////int main() {
//////////    try {
//////////        throw EDrived();
//////////    }
//////////    //注意：捕获的次序，子类必须在前面 
//////////    catch (EBase& e) { e.what(); }
//////////    catch (EDrived& e) { e.what(); }
//////////    return 0;
//////////}
////////#include <iostream>
////////using namespace std;
////////class A
////////{
////////public:
////////	virtual void func(int val = 1)
////////	{
////////		std::cout << "A->" << val << std::endl;
////////	}
////////	virtual void test()
////////	{
////////		func();
////////	}
////////};
////////class B : public A
////////{
////////public:
////////	void func(int val = 0)
////////	{
////////		std::cout << "B->" << val << std::endl;
////////	}
////////};
////////int main(int argc, char* argv[])
////////{
////////	B* p = new B; p->test(); 
////////	return 0;
////////}
////////
////////#include<iostream>
////////using namespace std;
////////double& f(double x)
////////{
////////	double y;
////////	y = sin(x);
////////	return y;
////////}
////////int main()
////////{
////////	double a = 3.14 / 6;
////////	double y;
////////	y = f(a);
////////	cout << "y = " << y << endl;
////////	return 0;
////////}
//////
////////#include <iostream>
////////#include <array>
////////using namespace std;
////////void dis_1(const int x) {
////////	//错误， x是只读的变量
////////	array <int, x>
////////		myarr{1, 2, 3, 4, 5};
////////	cout << myarr[1] << endl;
////////}
////////void dis_2() {
////////	const int x = 5;
////////	array <int, x>
////////		myarr{1, 2, 3, 4, 5};
////////	cout << myarr[1] << endl;
////////}
////////int main()
////////{
////////	dis_1(5);
////////	dis_2();
////////}
//////
//////
//////#include <iostream>
//////#include <string>
//////using namespace std;
////////class A
////////{
////////	int a = 5;
////////public:
////////	void change(int i) {
////////		a = i;
////////	}
////////	static void value_of_a() {
////////		//cout << a;
////////	}
////////};
//////class B
//////{
//////public:
//////    //int func() = default;  // 1
//////
//////    //B(int, int) = default;  // 2
//////
//////    B(int) = default;  // 3
//////};
//////
//////int main(int argc, char const* argv[])
//////{
//////	A a1 = A();
//////	a1.change(10);
//////	a1.value_of_a();
//////	return 0;
//////}
////
//////#include <iostream>
//////using namespace std;
//////ostream& operator<<(ostream& i, int n)
//////{
//////	return i;
//////}
//////int main()
//////{
//////	cout << 5 << endl;
//////	cin.get();
//////	return 0;
//////}
////#include <iostream>
////
////class Base {
////public:
////    Base(int id) : m_id(id) {}
////
////    void GetId() {
////        m_id++;
////        std::cout << m_id << std::endl;
////    }
////
////protected:
////    void GetZero() {
////        std::cout << 0 << std::endl;
////    }
////
////private:
////    int m_id;
////};
////
////class Child : private Base {
////public:
////    Child() : Base(6) {}
////
////    void GetIdInChild() {
////        GetId();
////    }
////
////    void GetZeroInChild() {
////        GetZero();
////    }
////};
////
////int main() {
////    Child child;
////    child.GetId();
////    //child.GetZero();
////
////    return 0;
////}
//
//#include <iostream>
//using namespace std;
//class Base
//{
//public:
//    void fun1()
//    {
//        fun2();
//    }
//
//    virtual void fun2()
//    {
//        cout << "Base::fun2()" << endl;
//    }
//};
//
//class Derived : public Base
//{
//public:
//    virtual void fun2()
//    {
//        cout << "Derived:fun2()" << endl;
//    }
//};
//
//int main()
//{
//    Derived d;
//    Base* pBase = &d;
//    pBase->fun1();
//    return 0;
//}
#include <iostream>
#include <string>
using namespace std;
class Person {
public:
	void printInfo() {
		cout << getInfo() << " ";
	}
	string getInfo() {
		return "Person";
	}
};
class Student : public Person {
public:
	string getInfo() {
		return "Student";
	}
};
int main() 
{
	cout << 1234.5678 << endl;
}