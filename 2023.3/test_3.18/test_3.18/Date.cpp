//#include "Date.h"
//#include <iostream>
//using namespace std;
//DATE::DATE()
//{
//	this->year = 1970;
//	this->month = 1;
//	this->day = 1;
//}
//DATE::DATE(int year, int month, int day)
//{
//	this->year = year;
//	this->month = month;
//	this->day = day;
//}
//DATE::~DATE()
//{
//	cout << "The DATE CLASS will be destroyed." << endl;
//}
//int DATE::getMonth() const
//{
//	return this->month;
//}
//int DATE::getDay() const
//{
//	return this->day;
//}
//int DATE::getYear() const
//{
//	return this->year;
//}
//void DATE::Print() const
//{//January 1, 1970
//	string month[13] = { "","January","February","March","April","May","June","July","August","September","October","November","December" };
//	cout << month[this->getMonth()] << " " << this->getDay() << ", " << this->getYear() << endl;
//}
//void DATE::Increment()
//{
//	(this->day)++;
//	int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int year = this->year;
//	if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
//		day[3]++;
//	if (this->day > day[this->month])
//	{
//		this->day = 1;
//		(this->month)++;
//	}
//	if (this->month > 12)
//	{
//		this->month = 1;
//		(this->year)++;
//	}
//}
//void DATE::Decrement()
//{
//	(this->day)--;
//	int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int year = this->year;
//	if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
//		day[3]++;
//	if (this->day == 0)
//	{
//		(this->month)--;
//		this->day = day[this->month];
//	}
//	if (this->month == 0)
//	{
//		(this->year)--;
//		this->month = 12;
//	}
//}