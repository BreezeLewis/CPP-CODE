#pragma once
#include <iostream>
#include <algorithm>

//template<class T>

class Matrix
{
	friend std::istream& operator>>(std::istream& is, Matrix& m);
	friend std::ostream& operator<<(std::ostream& os, Matrix& m);
	friend Matrix operator+(const Matrix& m1, const Matrix& m2);
	friend Matrix operator-(const Matrix& m1, const Matrix& m2);
private:
	int** data;
	int row;
	int col;
public:
	Matrix() :data(nullptr), row(0), col(0)
	{}
	Matrix(int r, int c) :row(r), col(c)
	{
		data = new int* [r];
		for (int i = 0; i < r; i++)
			data[i] = new int[c];
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				data[i][j] = 0;
	}
	Matrix(int** d, int r, int c) :row(r), col(c)
	{
		data = new int* [r];
		for (int i = 0; i < r; i++)
			data[i] = new int[c];
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				data[i][j] = d[i][j];
	}
	Matrix(const Matrix& m)
	{
		row = m.row;
		col = m.col;
		data = new int* [row];
		for (int i = 0; i < row; i++)
			data[i] = new int[col];
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				data[i][j] = m.data[i][j];
			}
	}
	void swap(const Matrix& m1, const Matrix& m2)
	{
		std::swap(m1.data, m2.data);
		std::swap(m1.row, m2.row);
		std::swap(m1.col, m2.col);
	}
	Matrix& operator=(Matrix m)
	{
		swap(*this, m);
		return *this;
	}
	Matrix& operator=(int** d)
	{
		Matrix ret(d, row, col);
		swap(*this, ret);
		return ret;
	}
	virtual ~Matrix()
	{
		for (int i = 0; i < row; i++)
			delete[] data[i];
		delete[] data;
	}
	Matrix transpose()
	{
		int** d = new int* [col];
		for (int i = 0; i < col; i++)
			for (int j = 0; j < row; j++)
				d[i][j] = data[j][i];

		Matrix ret(d, col, row);

		return ret;
	}
	bool isTriangular()
	{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < i; j++)
				if (data[i][j] != 0)
					return false;
		return true;
	}
	int& getElement(int r, int c)
	{
		return data[r][c];
	}
	int getRow() const
	{
		return row;
	}
	int getCol() const
	{
		return col;
	}
	void add(Matrix b)
	{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				data[i][j] += b.data[i][j];
			}
	}
	Matrix plus(Matrix b)
	{
		return *this + b;
	}
	void print()
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				std::cout << data[i][j] << " ";
			std::cout << std::endl;
		}
	}
};

std::istream& operator>>(std::istream& is, Matrix& m)
{
	int r = m.row;
	int c = m.col;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			std::cin >> m.data[i][j];
		}
	return is;
}
std::ostream& operator<<(std::ostream& os, Matrix& m)
{
	m.print();

	return os;
}
Matrix operator+(const Matrix& m1, const Matrix& m2)
{
	Matrix ret(m1);
	for (int i = 0; i < m1.row; i++)
	{
		for (int j = 0; j < m1.col; j++)
		{
			ret.data[i][j] += m2.data[i][j];
		}
	}
	return ret;
}
Matrix operator-(const Matrix& m1, const Matrix& m2)
{
	Matrix ret(m1);
	for (int i = 0; i < m1.row; i++)
	{
		for (int j = 0; j < m1.col; j++)
		{
			ret.data[i][j] -= m2.data[i][j];
		}
	}
	return ret;
}