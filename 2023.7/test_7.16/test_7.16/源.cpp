//#include <iostream>       
//using namespace std;
//
//class EBase {
//    //EX1����� virtual �Ƚ������ͬ 
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
//    //ע�⣺����Ĵ������������ǰ�� 
//    catch (EBase& e) { e.what(); }
//    catch (EDrived& e) { e.what(); }
//    return 0;
//}

#include <iostream>       
using namespace std;

void f3(int x) {
    switch (x) {
    case 1: throw 3.4;	      // �׳�double���쳣
    case 2: throw 2.5f; 	    // �׳�float���쳣
    case 3: throw 1;   	      // �׳�int���쳣
    }
    cout << "End of f3" << endl;
}

void f2(int x) {
    try {
        f3(x);
    }
    catch (int) {	    //int���쳣�Ĵ������
        cout << "An int exception occurred!--from f2" << endl;
    }
    catch (float) { 	//float���쳣�Ĵ������
        cout << "A float exception occurred!--from f2" << endl;
    }
    cout << "End of f2" << endl;
}

void f1(int x) {
    try {
        f2(x);
    }
    catch (int) {  	            // int���쳣�Ĵ������
        cout << "An int exception occurred!--from f1" << endl;
    }
    catch (float) {  	            // float���쳣�Ĵ������
        cout << "A float exception occurred!--from f1" << endl;
    }
    catch (double) { 	            // double���쳣�Ĵ������
        cout << "A double exception occurred!--from f1" << endl;
    }
    cout << "End of f1" << endl;
}

int main()
{
    f1(0);
    return 0;
}