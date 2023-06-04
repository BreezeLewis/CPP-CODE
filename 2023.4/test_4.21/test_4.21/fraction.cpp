#include "fraction.h"
fraction::fraction(const int& son, const int& mom)
{
    if (son == mom && son && mom)
    {
        _numerator = _denominator = 1;
        return;
    }
    _numerator = son;
    _denominator = mom;
}
// The numerator and the denominator
// fraction(5) = 5/1 = 5 :)
fraction::fraction(const fraction& f)
{
    _numerator = f._numerator;
    _denominator = f._denominator;
}
// copy constructor
int fraction::gcd(const int& a, const int& b) const
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
// If you don't need this method, just ignore it.
void fraction::simp()
{
    int ret = gcd(_numerator, _denominator);
    _numerator /= ret;
    _denominator /= ret;
}
void fraction::operator=(const fraction& f)
{
    _numerator = f._numerator;
    _denominator = f._denominator;
}

// You must know the meaning of +-*/, don't you ?
fraction fraction::operator+(const fraction& f) const
{
    fraction ret(f);
    if (_denominator == 0 || f._denominator == 0)
    {
        ret._denominator = 0;
        return ret;
    }
    int a = _numerator, b = _denominator;
    int c = f._numerator, d = f._denominator;
    int mom = b * d, son = a * d + b * c;
    ret._numerator = son, ret._denominator = mom;
    ret.simp();
    if (ret._numerator > 0 && ret._denominator < 0)
    {
        ret._numerator *= -1;
        ret._denominator *= -1;
    }
    return ret;
}
fraction fraction::operator-(const fraction& f) const
{
    fraction ret(f);
    if (_denominator == 0 || f._denominator == 0)
    {
        ret._denominator = 0;
        return ret;
    }
    int a = _numerator, b = _denominator;
    int c = f._numerator, d = f._denominator;
    int mom = b * d, son = a * d - b * c;
    ret._numerator = son, ret._denominator = mom;
    ret.simp();
    if (ret._numerator > 0 && ret._denominator < 0)
    {
        ret._numerator *= -1;
        ret._denominator *= -1;
    }
    return ret;
}
fraction fraction::operator*(const fraction& f) const
{
    fraction ret(f);
    if (_denominator == 0 || f._denominator == 0)
    {
        ret._denominator = 0;
        return ret;
    }
    int a = _numerator, b = _denominator;
    int c = f._numerator, d = f._denominator;
    int mom = b * d, son = a * c;
    ret._numerator = son, ret._denominator = mom;
    ret.simp();
    if (ret._numerator > 0 && ret._denominator < 0)
    {
        ret._numerator *= -1;
        ret._denominator *= -1;
    }
    return ret;
}
fraction fraction::operator/(const fraction& f) const
{
    fraction ret(f);
    if (_denominator == 0 || f._denominator == 0 || f._numerator == 0)
    {
        ret._denominator = 0;
        return ret;
    }
    int a = _numerator, b = _denominator;
    int c = f._denominator, d = f._numerator;
    int mom = b * d, son = a * c;
    ret._numerator = son, ret._denominator = mom;
    ret.simp();
    if (ret._numerator > 0 && ret._denominator < 0)
    {
        ret._numerator *= -1;
        ret._denominator *= -1;
    }
    return ret;
}

void fraction::operator+=(const fraction& f)
{
    (*this) = (*this) + f;
}
void fraction::operator-=(const fraction& f)
{
    (*this) = (*this) - f;
}
void fraction::operator*=(const fraction& f)
{
    (*this) = (*this) * f;
}
void fraction::operator/=(const fraction& f)
{
    (*this) = (*this) / f;
}

// Comparison operators
bool fraction::operator==(const fraction& f) const
{
    if (_denominator == 0 && f._denominator == 0)
        return true;
    if (_denominator == 0 || f._denominator == 0)
        return false;
    int a = this->_numerator, b = this->_denominator;
    int c = f._numerator, d = f._denominator;
    if ((double)a / b == (double)c / d)
        return true;
    if (_numerator == _denominator && f._numerator == f._denominator)
        return true;
    if (_numerator == f._numerator && _denominator == f._denominator)
        return true;
    return false;
}
bool fraction::operator!=(const fraction& f) const
{
    return !(*this == f);
}
bool fraction::operator<(const fraction& f) const
{
    if (_denominator == 0 || f._denominator == 0)
        return false;
    int a = _numerator, b = _denominator;
    int c = f._numerator, d = f._denominator;
    double x = (double)a / b;
    double y = (double)c / d;
    if (x < y)
        return true;
    return false;
}
bool fraction::operator>(const fraction& f) const
{
    if (_denominator == 0 || f._denominator == 0)
        return false;
    int a = _numerator, b = _denominator;
    int c = f._numerator, d = f._denominator;
    double x = (double)a / b;
    double y = (double)c / d;
    if (x > y)
        return true;
    return false;
}
bool fraction::operator<=(const fraction& f) const
{
    if (_denominator == 0 || f._denominator == 0)
        return false;
    return !(*this > f);
}
bool fraction::operator>=(const fraction& f) const
{
    if (_denominator == 0 || f._denominator == 0)
        return false;
    return !(*this < f);
}

std::istream& operator>>(std::istream& is, fraction& f)
{
    return is >> f._numerator >> f._denominator;
}
// Input Format: two integers with a space in it
// "a b" is correct. Not "a/b"
std::ostream& operator<<(std::ostream& os, const fraction& f)
{
    if (f._denominator == 0)
        return os << "NaN";

    if (f._denominator == 1)
        return os << f._numerator;
    else
        return os << f._numerator << "/" << f._denominator;
}
// Normally you should output "a/b" without any space and LF
// Sometims you may output a single integer (Why? Guess XD)
// If it is not a number (den = 0), output "NaN"