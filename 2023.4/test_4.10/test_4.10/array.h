#ifndef ARRAY
#define ARRAY

#include <iostream>

class array
{
private:
    int size;         // size
    int* data;        // dynamically allocate/release memory
    int* ref_counter; // reference counter

    void copy_on_write(); // copy on write

public:
    array();
    array(int size, int val);
    array(const array& another)
    {
        data = nullptr;
        ref_counter = nullptr;
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
    int get_ref_counter() { return *ref_counter; }
    int* get_data() { return data; }
};

#endif