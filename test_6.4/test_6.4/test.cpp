//#include <iostream>
//using namespace std;
//class Base {
//public:
//    virtual void print() const {
//        cout << "Base ";
//    }
//};
//class DerivedOne : virtual public Base {
//public:
//    void print() const
//    {
//        cout << "DerivedOne ";
//    }
//};
//class DerivedTwo : virtual public Base {
//public:
//    void print() const
//    {
//        cout << "DerivedTwo ";
//    }
//};
//class Multiple : public DerivedOne, DerivedTwo {
//public:
//    void print() const
//    {
//        cout << "Multiple ";
//    }
//};
//int main() {
//    Multiple both;
//    DerivedOne one;
//    DerivedTwo two;
//    Base* array[3];
//    array[0] = &both;
//    array[1] = &one;
//    array[2] = &two;
//    for (int i = 0; i < 3; i++)
//        array[i]->print();
//    return 0;
//}

//
//
//#include <iostream>
//using namespace std;
//
//class Base
//{
//public:
//	void Print()
//	{
//		cout << "hello" << endl;
//	}
//};
//
//class Derive:public Base
//{
//public:
//
//};
//
//int main()
//{
//
//	
//
//	return 0;
//}

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

#include<iostream>
using namespace std;

class Base
{
public:
    Base() { cout << "create Base" << endl; }
    virtual ~Base() { cout << "delete Base" << endl; }
    //~Base() { cout << "delete Base" << endl; }
};

class Der : public Base
{
public:
    Der() { cout << "create Der" << endl; }
    ~Der() { cout << "Delete Der" << endl; }
};

int main(int argc, char const* argv[])
{
    Base* b = new Der;
    delete b;

    return 0;
}