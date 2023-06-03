//#include <iostream>
//using namespace std;
//
//class B {
//public:
//    void hello() const {
//        std::cout << "Hello world, this is B!\n";
//    }
//};
//class D : public B {
//public:
//    void hello() const {
//        std::cout << "Hello world, this is D!\n";
//    }
//};
//int main()
//{
//    D d;
//    B& br = d;
//    br.hello();
//    D& another_d = static_cast<D&>(br);
//    another_d.hello();
//}
//#include <iostream>
//struct Base {
//    virtual ~Base() {}
//};
//struct Derived : Base {
//    virtual void name() {}
//};
//int main() {
//    Base* b1 = new Base;
//    if (Derived* d = dynamic_cast<Derived*>(b1)) {
//        std::cout << "downcast from b1 to d successful\n";
//        d->name();
//    }
//    Base* b2 = new Derived;
//    if (Derived* d = dynamic_cast<Derived*>(b2)) {
//        std::cout << "downcast from b2 to d successful\n";
//        d->name();
//    }
//    delete b1;
//    delete b2;
//    return 0;
//}
#include <iostream>
using namespace std;
int main() {
    const int n = 25;
    int* p = const_cast<int*>(&n);
    *p = 33;
    cout << "n = " << n << endl;
    cout << "*p = " << *p << endl;
    return 0;
}