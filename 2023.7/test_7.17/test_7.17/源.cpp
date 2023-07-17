////#include <stdexcept>
////#include <iostream>
////using namespace std;
////
////class Divided_By_Zero :public runtime_error {
////public:
////    explicit Divided_By_Zero(const string& s = "Divide By Zero")
////        :runtime_error(s) 
////    {};
////    explicit Divided_By_Zero(const char* s) 
////        :runtime_error(string(s)) 
////    {};
////};
////
////int main() {
////    double a = 10, b = 0, res;
////    double c = 10, d = 1;
////    char Operator = '/';
////    try {
////        if (b == 0) throw Divided_By_Zero();
////        res = a / b;
////        cout << a << " / " << b << " = " << res << endl;
////        if (d == 0) throw Divided_By_Zero();
////        res = c / d;
////        cout << c << " / " << d << " = " << res << endl;
////    }
////    catch (const exception& e) {
////        cout << e.what() << endl;
////    }
////    return 0;
////}
//
//#include <iostream>
//class Dummy {
//public:
//    ~Dummy() {
//        std::cout << "Dummy destructed\n";
//    }
//};
//
//class Triangle {
//public:
//    Triangle(int a = 3, int b = 4, int c = 5) {
//        if (a < 0) { throw a; }
//    }
//    ~Triangle() {
//        std::cout << "Triangle destructed\n";
//    }
//private:
//    int a, b, c;
//};
//
//int main() {
//    try {
//        Dummy dum;
//        //if new or alloc something? 
//        Triangle tri(-1);
//        std::cout << "Triangle created\n";
//    }
//    catch (...) {
//        std::cout << "Exception catched\n";
//    }
//}

#include <exception>
#include <iostream>
#include <string>
#include <typeinfo>
#include <stdexcept>
using namespace std;

int main() {
	try {
		string str("a");
		string rstr("bcd");
		str.append(rstr, 1, 5);
		cout << str << endl;
		str.append(rstr, 2, 5);
		cout << str << endl;
		str.append(rstr, 4, 5);
		cout << str << endl;
	}
	catch (const exception& e) {
		cerr << "Caught: " << e.what() << endl;
		cerr << "Type: " << typeid(e).name() << endl;
	}
}