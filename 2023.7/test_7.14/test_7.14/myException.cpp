#include <iostream>
#include <string>
#include <cmath>
#include "myException.hpp"
// 自定义异常类 MyException

MyException::MyException(const std::string msg) :message(msg) {}

std::string MyException::what()
{
    return message;
}



