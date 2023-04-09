#include <iostream>
#include "array.h"
// 分配可以容纳row x col个元素的内存，每个元素赋值为val 
array2d::array2d(int row, int col, int val)
{
    this->row = row, this->col = col;
    data = new array[row];

    for (int i = 0; i < row; i++)
    {
        array a(col, val);
        (data + i)->deep_copy(a);
    }
}
// 析构函数
array2d::~array2d()
{
    delete[] data;
    data = nullptr;
    row = 0;
    col = 0;
}
// 如果(i,j)不越界，则将(i,j)位置的元素赋值为val，返回true；如果(i,j)越界，则返回false 
bool array2d::assign(int i, int j, int val)
{
    if (i < 0 || j < 0 || i >= row || j >= col)
        return false;

    (*(data + i)).assign(j, val);
    return true;
}
// 深拷贝函数
void array2d::deep_copy(const array2d& another)
{
    array* del = data;
    row = another.row, col = another.col;
    data = new array[row];

    for (int i = 0; i < row; i++)
        (*(data + i)).deep_copy(*(another.data + i));

    delete[] del;
}



array::array(int size, int val)
{
    this->size = size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = val;
}
void array::deep_copy(const array& another)
{
    int* del = data;
    size = another.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = another.data[i];
    delete[] del;
}
array::~array()
{
    delete[] data;
    data = nullptr;
    size = 0;
}
bool array::assign(int pos, int val)
{
    if (pos < 0 || pos >= size)
        return false;
    data[pos] = val;
    return true;
}
array::array()
{
    data = new int[4];
    size = 4;
}