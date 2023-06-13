#include <iostream>
#include "calculator.h"
using namespace std;


int main()
{
    //加法
    AbstractCalculator* abc = new Add;
    cin >> abc->m_num1 >> abc->m_num2;
    cout << abc->m_num1 << " + " << abc->m_num2 << " = " << abc->getResult() << endl;
    delete abc;

    //减法
    abc = new Sub;
    cin >> abc->m_num1 >> abc->m_num2;
    cout << abc->m_num1 << " - " << abc->m_num2 << " = " << abc->getResult() << endl;
    delete abc;

    //乘法
    abc = new Mul;
    cin >> abc->m_num1 >> abc->m_num2;
    cout << abc->m_num1 << " * " << abc->m_num2 << " = " << abc->getResult() << endl;
    delete abc;

    return 0;
}