#include <iostream>
#include <iomanip>
using namespace std;

#include "source.h"


int main(int argc, const char* argv[]) {
	Accountant py;
	Circle* a = new Circle(179, 2938);   //��һ������Ϊ�뾶���ڶ�������Ϊ��λ����۸�
	Square* b = new Square(90.8, 1290);  //��һ������Ϊ�߳����ڶ�������Ϊ��λ����۸�
	py.DevelopEstate(a);
	cout << setprecision(10) << py.CheckMoney() << endl;
	py.DevelopEstate(b);
	cout << setprecision(10) << py.CheckMoney() << endl;

	return 0;
}
