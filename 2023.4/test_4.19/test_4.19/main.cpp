#include <vector>
#include <numeric>
#include <iostream>
#include<cstdlib>
#include "complex.h"
using namespace std;

int main()
{
    int val_1, val_2, val_3;
    cin >> val_1 >> val_2;
    COMPLEX c1(val_1, val_2); // ����һ��ֵΪval_1 + val_2*i�ĸ���c1
    cin >> val_3;
    COMPLEX c2(val_3);    // ����һ��ֵΪval_3 + 0*i�ĸ���c2
    COMPLEX c3(c1);   // �ÿ������캯������һ��ֵͬc1���¸���

    c3.print();        // ��ӡc3��ֵ
    c1 = c1 + c2 + c3; // ��c1����c2�ټ���c3��ֵ��c1
    c2 = -c3;          // c2����c3��
    c3 = c2 - c1;      // c3����c2��ȥc1
    c3.print();        // �ٴ�ӡ�����c3��ֵ

    COMPLEX temp = c3++;
    temp.print();
    c3.print();

    temp = c3--;
    temp.print();
    c3.print();

    temp = --c3;
    temp.print();
    c3.print();

    temp = ++c3;
    temp.print();
    c3.print();



    return 0;
}

