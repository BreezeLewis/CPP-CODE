#include <iostream>
#include <cmath>
using namespace std;
#include "myException.hpp"
#include "mySqrt.hpp"
// ʵ�� sqrt ��������������Ƿ�������׳��쳣
double mySqrt(double x)
{
    if (x < 0)
        throw MyException("invalid argument");

    return sqrt(x);
}