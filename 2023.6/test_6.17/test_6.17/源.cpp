#include <iostream>
using namespace std;
//class A
//{
//public:
//    virtual void func(int x) {
//        cout << "func() in class A with input " << x << endl;
//    }
//};
//
//class B : public A
//{
//public:
//    void func(int x)  {
//        cout << "func() in class B with input " << x << endl;
//    }
//};
//
//class C : public B
//{
//public:
//    void func(int x) {
//        cout << "func() in class C with input " << x << endl;
//    }
//};
//int main()
//{
//    A a; B b; C c;
//    A* arr[3] = { &a, &b, &c };
//    for (int i = 0; i < 3; i++)
//        arr[i]->func(i);
//    return 0;
//}


class Cat
{
public:
    // three overloaded functions
    virtual void func() const
    {
        cout << "func default" << endl;
    }

    virtual void func(int a) const
    {
        cout << "func with int" << endl;
    }

    virtual void func(double x) const
    {
        cout << "func with double" << endl;
    }

    virtual void func(string str) const
    {
        cout << "func with string" << endl;
    }
};

class persianCat : public Cat
{
public:
    // new redefined functions
    virtual void func() const
    {
        cout << "new func default" << endl;
    }

    virtual void func(int a_) const
    {
        cout << "new func with int" << endl;
    }
};

int main()
{
    Cat bai;
    persianCat hei;
    persianCat& r2persianCat = hei;
    r2persianCat.func();
    r2persianCat.func(2);
    r2persianCat.func(2.1);
    return 0;
}