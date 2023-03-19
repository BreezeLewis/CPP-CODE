//#include <iostream>
//#include "Person.hpp"
//using namespace std;
//Date::Date()
//{
//	year = month = day = 0;
//}
//Date::Date(int year, int month, int day)
//{
//	this->year = year;
//	this->month = month;
//	this->day = day;
//}
//int Date::getYear()
//{
//	return this->year;
//}
//void Date::setYear(int year)
//{
//	this->year = year;
//}
//int Date::getMonth()
//{
//	return this->month;
//}
//int Date::getDay()
//{
//	return this->day;
//}
//void Date::setMonth(int month)
//{
//	this->month = month;
//}
//void Date::setDay(int day)
//{
//	this->day = day;
//}
//void Date::Print()
//{
//	printf("%d %d %d\n", this->year, this->month, this->day);
//}
//Person::Person(int id, int year, int month, int day)
//{
//	this->birthDate = new Date(year, month, day);
//	(this->numberOfObjects)++;
//	this->birthDate->setDay(day);
//	this->birthDate->setMonth(month);
//	this->birthDate->setYear(year);
//	this->id = id;
//}
//Person::~Person()
//{
//	(this->numberOfObjects)--;
//	delete this->birthDate;
//}
//int Person::getId()
//{
//	return this->id;
//}
//Date* Person::getBirthDate() const
//{
//	return this->birthDate;
//}
//int Person::numberOfObjects = 0;
//int Person::getNumberOfObjects() //return the number of Person objects 
//{
//	return Person::numberOfObjects;
//}