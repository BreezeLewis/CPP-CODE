#include <iostream>
#include <string>
#include <cmath>
#include "myException.hpp"
// �Զ����쳣�� MyException

MyException::MyException(const std::string msg) :message(msg) {}

std::string MyException::what()
{
    return message;
}



