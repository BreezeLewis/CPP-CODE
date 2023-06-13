#include <iostream>
#include "calculator.h"
using namespace std;


int main()
{
    //�ӷ�
    AbstractCalculator* abc = new Add;
    cin >> abc->m_num1 >> abc->m_num2;
    cout << abc->m_num1 << " + " << abc->m_num2 << " = " << abc->getResult() << endl;
    delete abc;

    //����
    abc = new Sub;
    cin >> abc->m_num1 >> abc->m_num2;
    cout << abc->m_num1 << " - " << abc->m_num2 << " = " << abc->getResult() << endl;
    delete abc;

    //�˷�
    abc = new Mul;
    cin >> abc->m_num1 >> abc->m_num2;
    cout << abc->m_num1 << " * " << abc->m_num2 << " = " << abc->getResult() << endl;
    delete abc;

    return 0;
}