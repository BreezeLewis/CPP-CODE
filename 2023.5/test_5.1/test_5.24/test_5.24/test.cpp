//#include <iostream>
//using namespace std;
//class A
//{
//public:
//    A(int n)
//    {
//        cout << n;
//    }
//};
//class B : public A
//{
//public:
//    B(int n, double d)
//        : A(n)
//    {
//        cout << d;
//    }
//};
//class C : public B
//{
//public:
//    C(int n, double d, char ch)
//        : B(n, d)
//    {
//        cout << ch;
//    }
//};
//int main()
//{
//    C c(5, 4.3, 'R');
//    return 0;
//}



//#include <iostream>
//using namespace std;
//class BaseClass
//{
//protected:
//    int i;
//public:
//    BaseClass(int x)
//    {
//        i = x;
//    }
//    ~BaseClass()
//    {
//    }
//};
//class DerivedClass : public BaseClass
//{
//    int j;
//public:
//    DerivedClass(int x, int y) : BaseClass(y)
//    {
//        j = x;
//    }
//    ~DerivedClass()
//    {
//    }
//    void show()
//    {
//        cout << i << " " << j << endl;
//    }
//};
//int main()
//{
//    DerivedClass ob(3, 4);
//    ob.show();
//    return 0;
//}

//#include <iostream>
//using namespace std;
//class Base
//{
//public:
//    int m;
//    Base(int n = 0) : m(n)
//    {
//        cout << "Base" << endl;
//    }
//};
//class Derived : public Base
//{
//public:
//    double d;
//    Derived(double de = 0.0) : d(de)
//    {
//        cout << "Derived" << endl;
//    }
//};
//int main()
//{
//    cout << "Instantiating Base" << endl;
//    Base cBase;
//    cout << "Instantiating Derived" << endl;
//    Derived cDerived;
//    return 0;
//}


//#include <iostream>
//using namespace std;
//class Parent
//{
//public:
//    Parent()
//    {
//        cout << "Parent()\n";
//    }
//    Parent(int i)
//    {
//        cout << "Parent(" << i << ")\n";
//    };
//    ~Parent()
//    {
//        cout << "~Parent()\n";
//    };
//};
//class Child : public Parent
//{
//public:
//    Child()
//    {
//        cout << "Child()\n";
//    }
//    Child(int i) : Parent(i)
//    {
//        cout << "Child(" << i << ")\n";
//    }
//    ~Child()
//    {
//        cout << "~Child()\n";
//    }
//};
//int main()
//{
//    Child b;
//    Child c(42);
//    return 0;
//}


