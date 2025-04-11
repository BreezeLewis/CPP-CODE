#include <iostream>

using namespace std;

class Base {
public:
    virtual void func1(int x = 10) {
        cout << "Base: " << x << endl;
    }

    virtual void func2()
    {
        
    }

    void func3()
    {

    }
};

class Derived : public Base {
public:
    virtual void func1(int x = 20) override {
        cout << "Derived: " << x << endl;
    }

    virtual void func4()
    {
        cout << endl;
    }

    virtual void func5()
    {
        cout << endl;
    }

    int d = 5;
};

int main() {
    Base b;
    Derived d;
    return 0;
}