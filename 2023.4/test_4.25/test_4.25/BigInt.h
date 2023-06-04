<<<<<<< HEAD
#include <iostream>
#include <string>
using namespace std;
#define maxn 1000

class BigInt
{
public:
    friend std::ostream& operator << (std::ostream& os, BigInt x);
    string num;
    BigInt()
    {

    }
    BigInt(int i)
    {
        num = to_string(i);
    }
    BigInt(string s)
    {
        num = s;
    }
    void reverseStrToInt(int* a)
    {
        int len = 0;
        for (int i = num.size() - 1; i >= 0; i--)
        {
            a[len++] = num[i] - '0';
        }
    }
    BigInt operator+(BigInt x)
    {
        /*int* a = new int[num.size()];
        for (int i = 0;i < num.size();i++) a[i] = 0;
        int* b = new int[x.num.size()];
        for (int i = 0;i < num.size();i++) b[i] = 0;
        int* c = new int[num.size() + x.num.size() + 1];
        for (int i = 0;i < num.size();i++) c[i] = 0;*/
        int a[500] = { 0 };
        int b[500] = { 0 };
        int c[500] = { 0 };
        int size = num.size() > x.num.size() ? num.size() : x.num.size();
        reverseStrToInt(a);
        x.reverseStrToInt(b);
        for (int i = 0; i < size; i++)
        {
            c[i] = a[i] + b[i] + c[i];
            c[i + 1] = c[i] / 10;
            c[i] %= 10;
        }
        string ans = "";
        while (c[size] == 0)
            size--;
        for (int i = size; i >= 0; i--)
        {
            ans += c[i] + '0';
        }
        BigInt ret(ans);

        return ret;
    }
    BigInt operator=(BigInt x)
    {
        num = x.num;
        return *this;
    }
};

std::ostream& operator << (std::ostream& os, BigInt x)
{
    return os << x.num;
=======
#include <iostream>
#include <string>
using namespace std;
#define maxn 1000

class BigInt
{
public:
    friend std::ostream& operator << (std::ostream& os, BigInt x);
    string num;
    BigInt()
    {

    }
    BigInt(int i)
    {
        num = to_string(i);
    }
    BigInt(string s)
    {
        num = s;
    }
    void reverseStrToInt(int* a)
    {
        int len = 0;
        for (int i = num.size() - 1; i >= 0; i--)
        {
            a[len++] = num[i] - '0';
        }
    }
    BigInt operator+(BigInt x)
    {
        /*int* a = new int[num.size()];
        for (int i = 0;i < num.size();i++) a[i] = 0;
        int* b = new int[x.num.size()];
        for (int i = 0;i < num.size();i++) b[i] = 0;
        int* c = new int[num.size() + x.num.size() + 1];
        for (int i = 0;i < num.size();i++) c[i] = 0;*/
        int a[500] = { 0 };
        int b[500] = { 0 };
        int c[500] = { 0 };
        int size = num.size() > x.num.size() ? num.size() : x.num.size();
        reverseStrToInt(a);
        x.reverseStrToInt(b);
        for (int i = 0; i < size; i++)
        {
            c[i] = a[i] + b[i] + c[i];
            c[i + 1] = c[i] / 10;
            c[i] %= 10;
        }
        string ans = "";
        while (c[size] == 0)
            size--;
        for (int i = size; i >= 0; i--)
        {
            ans += c[i] + '0';
        }
        BigInt ret(ans);

        return ret;
    }
    BigInt operator=(BigInt x)
    {
        num = x.num;
        return *this;
    }
};

std::ostream& operator << (std::ostream& os, BigInt x)
{
    return os << x.num;
>>>>>>> cb73fa683f44cfac30efa94f2b3548a5d45d7a6c
}