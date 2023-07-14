#include <iostream>
#include <cmath>
using namespace std;
#include "myException.hpp"
#include "mySqrt.hpp"
// 实现 sqrt 函数，并在输入非法情况下抛出异常
double mySqrt(double x)
{
    if (x < 0)
        throw MyException("invalid argument");

    return sqrt(x);
}