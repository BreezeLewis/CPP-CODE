<<<<<<< HEAD
#include <vector>
#include <numeric>
#include <iostream>
#include<cstdlib>
#include "complex.h"
using namespace std;//COMPLEX::
COMPLEX::COMPLEX(double r, double i) // 构造函数
{
    real = r;
    image = i;
}
COMPLEX::COMPLEX(const COMPLEX& other)		 // 拷贝构造函数
{
    real = other.real;
    image = other.image;
}
void COMPLEX::print()						 // 打印复数
{
    cout << real;
    if (image > 0)
        cout << "+";
    cout << image << "i" << endl;
}

COMPLEX COMPLEX::operator+(const COMPLEX& other) // 重载加法运算符（二元）
{
    real += other.real;
    image += other.image;
    return *this;
}
COMPLEX COMPLEX::operator-(const COMPLEX& other) // 重载减法运算符（二元）
{
    real -= other.real;
    image -= other.image;
    return *this;
}
COMPLEX COMPLEX::operator-() // 重载求负运算符（一元）
{
    real *= -1;
    image *= -1;
    return *this;
}
COMPLEX COMPLEX::operator=(const COMPLEX& other)// 重载赋值运算符（二元）
{
    if (this != &other)
    {
        real = other.real;
        image = other.image;
    }
    return *this;
}

COMPLEX& COMPLEX::operator++()   //重载前置++
{
    real++;
    image++;
    return *this;
}
COMPLEX COMPLEX::operator++(int) //重载后置++
{
    COMPLEX ret(*this);
    real++;
    image++;
    return ret;
}
COMPLEX& COMPLEX::operator--()   //重载前置--
{
    real--;
    image--;
    return *this;
}
COMPLEX COMPLEX::operator--(int) //重载后置--
{
    COMPLEX ret(*this);
    real--;
    image--;
    return ret;
=======
#include <vector>
#include <numeric>
#include <iostream>
#include<cstdlib>
#include "complex.h"
using namespace std;//COMPLEX::
COMPLEX::COMPLEX(double r, double i) // 构造函数
{
    real = r;
    image = i;
}
COMPLEX::COMPLEX(const COMPLEX& other)		 // 拷贝构造函数
{
    real = other.real;
    image = other.image;
}
void COMPLEX::print()						 // 打印复数
{
    cout << real;
    if (image > 0)
        cout << "+";
    cout << image << "i" << endl;
}

COMPLEX COMPLEX::operator+(const COMPLEX& other) // 重载加法运算符（二元）
{
    real += other.real;
    image += other.image;
    return *this;
}
COMPLEX COMPLEX::operator-(const COMPLEX& other) // 重载减法运算符（二元）
{
    real -= other.real;
    image -= other.image;
    return *this;
}
COMPLEX COMPLEX::operator-() // 重载求负运算符（一元）
{
    real *= -1;
    image *= -1;
    return *this;
}
COMPLEX COMPLEX::operator=(const COMPLEX& other)// 重载赋值运算符（二元）
{
    if (this != &other)
    {
        real = other.real;
        image = other.image;
    }
    return *this;
}

COMPLEX& COMPLEX::operator++()   //重载前置++
{
    real++;
    image++;
    return *this;
}
COMPLEX COMPLEX::operator++(int) //重载后置++
{
    COMPLEX ret(*this);
    real++;
    image++;
    return ret;
}
COMPLEX& COMPLEX::operator--()   //重载前置--
{
    real--;
    image--;
    return *this;
}
COMPLEX COMPLEX::operator--(int) //重载后置--
{
    COMPLEX ret(*this);
    real--;
    image--;
    return ret;
>>>>>>> cb73fa683f44cfac30efa94f2b3548a5d45d7a6c
}