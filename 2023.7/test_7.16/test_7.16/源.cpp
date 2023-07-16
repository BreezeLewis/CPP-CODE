//#include <iostream>       
//using namespace std;
//
//class EBase {
//    //EX1：添加 virtual 比较输出不同 
//public: void what() { cout << "base" << endl; };
//};
//
//class EDrived :public EBase {
//public: void what() { cout << "EDrived" << endl; };
//};
//
//int main() {
//    try {
//        throw EDrived();
//    }
//    //注意：捕获的次序，子类必须在前面 
//    catch (EBase& e) { e.what(); }
//    catch (EDrived& e) { e.what(); }
//    return 0;
//}

#include <iostream>       
using namespace std;

void f3(int x) {
    switch (x) {
    case 1: throw 3.4;	      // 抛出double型异常
    case 2: throw 2.5f; 	    // 抛出float型异常
    case 3: throw 1;   	      // 抛出int型异常
    }
    cout << "End of f3" << endl;
}

void f2(int x) {
    try {
        f3(x);
    }
    catch (int) {	    //int型异常的处理代码
        cout << "An int exception occurred!--from f2" << endl;
    }
    catch (float) { 	//float型异常的处理代码
        cout << "A float exception occurred!--from f2" << endl;
    }
    cout << "End of f2" << endl;
}

void f1(int x) {
    try {
        f2(x);
    }
    catch (int) {  	            // int型异常的处理代码
        cout << "An int exception occurred!--from f1" << endl;
    }
    catch (float) {  	            // float型异常的处理代码
        cout << "A float exception occurred!--from f1" << endl;
    }
    catch (double) { 	            // double型异常的处理代码
        cout << "A double exception occurred!--from f1" << endl;
    }
    cout << "End of f1" << endl;
}

int main()
{
    f1(0);
    return 0;
}