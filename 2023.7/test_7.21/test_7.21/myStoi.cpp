#include <iostream>
#include <string>
#include <vector>
#include "myStoi.h"
#include "myException.h"
using namespace std;

int myStoi(string dnum)
{
    long long ret = 0;
    while (dnum[0] == ' ')
        dnum.erase(0,1);
    int flag = 1;
    if (dnum[0] == '+')
        flag = 1;
    else if (dnum[0] == '-')
        flag = -1;
    else if (!(dnum[0] >= '0' && dnum[0] <= '9'))
        throw string("Exception : invalid stoi argument");
    else ret = dnum[0] - '0';

    dnum.erase(0,1);
    for (size_t i = 0; i < dnum.size(); i++)
    {
        if (dnum[i] >= '0' && dnum[i] <= '9')
            ret = ret * 10 + dnum[i] - '0';
        else
            throw string("Exception : invalid stoi argument");
        //检查是否越界
        if (ret > 2147483647)
            throw string("Exception : stoi argument out of range");
    }


    return ret * flag;
}