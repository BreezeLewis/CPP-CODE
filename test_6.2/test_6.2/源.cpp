//#include<iostream>
//
//using namespace std;
//class B {
//public:
//
//	virtual void show() {
//		cout << "Base" << endl;
//	}
//};
//class D :public B {
//public:
//	void show() {
//		cout << "Derive" << endl;
//	}
//};
//
//void fun(B& ref) {
//	ref.show();
//}
//
//
//int main()
//{
//	D obj;
//	fun(obj);
//	return 0;
//}

#include <iostream>
using namespace std;
class B {
public:

	virtual void show() {
		cout << "Base" << endl;
	}
};
class D :public B {
public:
	void show() {
		cout << "Derive" << endl;
	}
};
void fun(B* ptr) {
	ptr->show();
}

int main()
{
	B* p = new D();
	fun(p);
	return 0;
}