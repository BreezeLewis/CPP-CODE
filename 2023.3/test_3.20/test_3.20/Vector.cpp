//#include <iostream>
//#include <cstring>
//#include "Vector.h"
//Vector::Vector(string name, int dim, int num[])
//{//construct a vector called myVector.
//	//printf("construct a vector called %s.\n", name);
//	cout << "construct a vector called " << name << "." << endl;
//	this->name = name;
//	this->dimension = dim;
//	int* arr = new int[dim];
//	for (int i = 0;i < dim;i++)
//		arr[i] = num[i];
//	this->param = arr;
//}
//Vector::~Vector()
//{
//	cout << "release memory from a vector called " << this->name << "." << endl;
//	delete[] (this->param);
//}
//void Vector::isEqual(const Vector& v)
//{
//	if (this->name == v.name)
//		cout << "same name, ";
//	else
//		cout << "different name, ";
//	int flag = 1;
//	//cmp
//	if (this->dimension != v.dimension)
//		flag = 0;
//	else
//	{
//		for (int i = 0;i < this->dimension;i++)
//		{
//			if ((this->param)[i] != v.param[i])
//				flag = 0;
//		}
//	}
//
//	if (flag)
//		cout << "same value.\n";
//	else
//		cout << "different value.\n";
//}
//void Vector::setName(string a)
//{
//	this->name = a;
//}
//void Vector::Print()
//{
//	cout << this->name << "(";
//	for (int i = 0;i < this->dimension - 1;i++)
//	{
//		/*cout << *((this->param) + i) << ",";*/
//		printf("%d, ", (this->param)[i]);
//	}
//	//cout << this->param[this->dimension - 1];
//	printf("%d", (this->param)[this->dimension - 1]);
//	cout << ")" << endl;
//}