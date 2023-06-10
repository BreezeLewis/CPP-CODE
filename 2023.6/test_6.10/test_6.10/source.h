#include <cmath>


class Land
{
public:
    double res = 0;
    double a, price;
    Land(double x, double p)
    {
        a = x, price = p;
    }

};

class Circle :public Land
{
public:
    Circle(double x, double p)
        : Land(x, p)
    {
        res = acos(-1) * x * x * p;
    }
};

class Square :public Land
{
public:
    Square(double x, double p)
        : Land(x, p)
    {
        res = x * x * p;
    }

};

class Accountant
{
public:
    double ans;
    void DevelopEstate(Land* land)
    {
        ans += land->res;
    }
    double CheckMoney()
    {
        return ans;
    }
};