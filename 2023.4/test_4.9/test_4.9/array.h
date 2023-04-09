#ifndef ARRAY
#define ARRAY

#include <iostream>

class array
{
private:
    int size;  // size
    int* data; // dynamically allocate/release memory

public:
    array();
    array(int size, int val);
    array(const array& another)
    {
        data = nullptr;
        deep_copy(another);
    }
    ~array();
    bool assign(int pos, int val);
    void deep_copy(const array& another);
    void print() const
    {
        for (int i = 0; i < size; ++i)
            std::cout << data[i] << std::endl;
    }
};

class array2d
{
private:
    int row;
    int col;
    array* data;

public:
    array2d(int row, int col, int val);
    array2d(const array2d& another)
    {
        data = nullptr;
        deep_copy(another);
    }
    ~array2d();
    bool assign(int i, int j, int val);
    void deep_copy(const array2d& another);
    void print() const
    {
        for (int i = 0; i < row; ++i)
        {
            data[i].print();
        }
    }
};
#endif