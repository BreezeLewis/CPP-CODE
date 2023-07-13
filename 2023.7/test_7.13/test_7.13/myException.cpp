#include<limits.h>
#include "myException.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
MyException::MyException(const std::string msg)
    :message(msg)
{

}
std::string MyException::what()
{
    return message;
}