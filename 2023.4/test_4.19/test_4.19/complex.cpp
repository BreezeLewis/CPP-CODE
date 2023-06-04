<<<<<<< HEAD
#include <vector>
#include <numeric>
#include <iostream>
#include<cstdlib>
#include "complex.h"
using namespace std;//COMPLEX::
COMPLEX::COMPLEX(double r, double i) // ���캯��
{
    real = r;
    image = i;
}
COMPLEX::COMPLEX(const COMPLEX& other)		 // �������캯��
{
    real = other.real;
    image = other.image;
}
void COMPLEX::print()						 // ��ӡ����
{
    cout << real;
    if (image > 0)
        cout << "+";
    cout << image << "i" << endl;
}

COMPLEX COMPLEX::operator+(const COMPLEX& other) // ���ؼӷ����������Ԫ��
{
    real += other.real;
    image += other.image;
    return *this;
}
COMPLEX COMPLEX::operator-(const COMPLEX& other) // ���ؼ������������Ԫ��
{
    real -= other.real;
    image -= other.image;
    return *this;
}
COMPLEX COMPLEX::operator-() // �������������һԪ��
{
    real *= -1;
    image *= -1;
    return *this;
}
COMPLEX COMPLEX::operator=(const COMPLEX& other)// ���ظ�ֵ���������Ԫ��
{
    if (this != &other)
    {
        real = other.real;
        image = other.image;
    }
    return *this;
}

COMPLEX& COMPLEX::operator++()   //����ǰ��++
{
    real++;
    image++;
    return *this;
}
COMPLEX COMPLEX::operator++(int) //���غ���++
{
    COMPLEX ret(*this);
    real++;
    image++;
    return ret;
}
COMPLEX& COMPLEX::operator--()   //����ǰ��--
{
    real--;
    image--;
    return *this;
}
COMPLEX COMPLEX::operator--(int) //���غ���--
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
COMPLEX::COMPLEX(double r, double i) // ���캯��
{
    real = r;
    image = i;
}
COMPLEX::COMPLEX(const COMPLEX& other)		 // �������캯��
{
    real = other.real;
    image = other.image;
}
void COMPLEX::print()						 // ��ӡ����
{
    cout << real;
    if (image > 0)
        cout << "+";
    cout << image << "i" << endl;
}

COMPLEX COMPLEX::operator+(const COMPLEX& other) // ���ؼӷ����������Ԫ��
{
    real += other.real;
    image += other.image;
    return *this;
}
COMPLEX COMPLEX::operator-(const COMPLEX& other) // ���ؼ������������Ԫ��
{
    real -= other.real;
    image -= other.image;
    return *this;
}
COMPLEX COMPLEX::operator-() // �������������һԪ��
{
    real *= -1;
    image *= -1;
    return *this;
}
COMPLEX COMPLEX::operator=(const COMPLEX& other)// ���ظ�ֵ���������Ԫ��
{
    if (this != &other)
    {
        real = other.real;
        image = other.image;
    }
    return *this;
}

COMPLEX& COMPLEX::operator++()   //����ǰ��++
{
    real++;
    image++;
    return *this;
}
COMPLEX COMPLEX::operator++(int) //���غ���++
{
    COMPLEX ret(*this);
    real++;
    image++;
    return ret;
}
COMPLEX& COMPLEX::operator--()   //����ǰ��--
{
    real--;
    image--;
    return *this;
}
COMPLEX COMPLEX::operator--(int) //���غ���--
{
    COMPLEX ret(*this);
    real--;
    image--;
    return ret;
>>>>>>> cb73fa683f44cfac30efa94f2b3548a5d45d7a6c
}