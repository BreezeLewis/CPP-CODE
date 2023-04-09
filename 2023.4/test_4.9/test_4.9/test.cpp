#include <iostream>
#include "array.h"

int main()
{
    int row, col, val;

    std::cin >> row >> col;
    array2d arr = array2d(row, col, -1);

    arr.print();

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            std::cin >> val;
            arr.assign(i, j, val);
        }
    }

    arr.print();

    array2d copy_arr = array2d(arr);

    copy_arr.print();

    for (int i = 0; i < 2 * row; ++i)
    {
        for (int j = 0; j < 2 * col; ++j)
        {
            std::cout << copy_arr.assign(i, j, i * j) << std::endl;
        }
    }

    copy_arr.print();
    arr.print();

    copy_arr.deep_copy(array2d(row / 2, col / 2, 1));
    copy_arr.print();
}