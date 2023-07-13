#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "myStoi.hpp"
#include "myException.hpp"


int myStoi(string dnum)
{
    while (dnum[0] == ' ')
        dnum.erase(0, 1);
    if (dnum.size() == 0)
        throw string("Exception : invalid stoi argument");
    if (dnum[1] == '+' || dnum[1] == '-')
    {
        throw string("Exception : invalid stoi argument");
        //return 0;
    }
    int flag = 1;
    int ret = 0;
    if (dnum[0] == '+')
        flag = 1;
    else if (dnum[0] == '-')
        flag = -1;
    else if (dnum[0] >= '0' && dnum[0] <= '9')
        ret = dnum[0] - '0';
    else
        throw string("Exception : invalid stoi argument");

    for (size_t i = 1; i < dnum.size(); i++)
    {
        if(!(dnum[i] >='0' && dnum[i] <='9'))
            throw string("Exception : invalid stoi argument");
        ret = ret * 10 + dnum[i] - '0';
    }

    if (dnum > "2147483647" && dnum.size() >= 10)
        throw string("Exception : stoi argument out of range");
    string cmp(dnum.begin() + 1, dnum.end());
    if (flag == -1 && cmp > "2147483648" && dnum.size() >= 10)
        throw string("Exception : stoi argument out of range");

    return flag * ret;
}