#include <iostream>
#include "array.h"
array::array(int size, int val)
{
    this->size = size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = val;
    ref_counter = new int(1);
}

void array::deep_copy(const array& another)
{
    if (this != &another)
    {
        int* del = data;
        int* delref = ref_counter;
        if (delref && *delref == 1)
            delete[] data, delete ref_counter;
        else if (delref)
            --(*delref);
        size = another.size;
        data = another.data;
        ref_counter = another.ref_counter;
        (*ref_counter)++;

    }
}

bool array::assign(int pos, int val)
{
    if (*ref_counter > 1)
    {
        (*ref_counter)--;
        int* newdata = new int[size];
        int* newref = new int(1);
        for (int i = 0; i < size; i++)
            newdata[i] = data[i];
        this->data = newdata;
        this->ref_counter = newref;
    }
    if (pos < 0 || pos >= size)
        return false;
    data[pos] = val;
    return true;
}

array::array()
{
    ref_counter = nullptr;
    data = nullptr;
    size = 0;
}

array::~array()
{
    if (*ref_counter == 1)
        delete[] data, delete ref_counter;
    else
        (*ref_counter)--;
}

void array::copy_on_write()
{

}