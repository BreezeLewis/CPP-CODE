#include <iostream>
#include "array.h"

int main()
{
    int n, m;

    std::cin >> n;
    array arr = array(n, -1);

    arr.print();

    for (int i = 0; i < n; ++i)
    {
        std::cin >> m;
        arr.assign(i, m);
    }

    arr.print();
    std::cout << arr.get_ref_counter() << std::endl;

    array copy_arr = array(arr);

    copy_arr.print();
    std::cout << (copy_arr.get_data() == arr.get_data()) << std::endl
        << copy_arr.get_ref_counter() << std::endl
        << arr.get_ref_counter() << std::endl;

    for (int i = 0; i < n; ++i)
    {
        copy_arr.assign(i, i);
    }

    copy_arr.print();
    arr.print();
    std::cout << (copy_arr.get_data() == arr.get_data()) << std::endl
        << copy_arr.get_ref_counter() << std::endl
        << arr.get_ref_counter() << std::endl;

    copy_arr.deep_copy(array(n / 2, 1));
    copy_arr.print();
    std::cout << copy_arr.get_ref_counter() << std::endl;

    copy_arr.deep_copy(copy_arr);
    std::cout << copy_arr.get_ref_counter() << std::endl;
}