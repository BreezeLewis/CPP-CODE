#pragma once
using namespace std;
class Number
{
public:
    int n;
    Number(int x)
    {
        n = x;
    }
    Number& add(int x)
    {
        n += x;
        return *this;
    }
    Number& sub(int x)
    {
        n -= x;
        return *this;
    }
    void print()
    {
        cout << n << endl;
    }
};