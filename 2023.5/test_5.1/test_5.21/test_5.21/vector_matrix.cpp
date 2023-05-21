#include<iostream>
#include <cmath>
#include"vector_matrix.h"
using namespace std;

Vector::Vector()
{
    dimension = 0;
    elements = nullptr;
}
Vector::Vector(int dim, const int* elements_)
{
    dimension = dim;
    int* p = new int[dim];

    for (int i = 0; i < dim; i++)
        p[i] = elements_[i];
    elements = p;
}
Vector::~Vector()
{
    delete[] elements;
}

int Vector::getDimension() const
{
    return dimension;
}
int* Vector::getElements() const
{
    return elements;
}
double Vector::getModule() const
{
    double res = 0;
    for (int i = 0; i < dimension; i++)
        res += elements[i] * elements[i];
    return sqrt(res);
}

Matrix::Matrix()
{
    row = 0;
}
Matrix::Matrix(int row, int col, const int* elements_)
    :Vector(row* col, elements_)
{
    this->row = row;

}
bool Matrix::Symmetric() const
{
    int col = getDimension() / row;
    if (row != col)
        return 0;
    bool res = 1;
    int* ele = getElements();
    for (int i = 0; i < row; i++)
        if (ele[i] != ele[i * row])
            res = 0;

    return res;
}