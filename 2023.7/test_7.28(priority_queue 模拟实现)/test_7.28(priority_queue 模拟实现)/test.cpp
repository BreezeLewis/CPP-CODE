#include <iostream>
using namespace std;

#include "Priority_Queue.h"
using namespace Lewis;
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}

	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}

	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}

private:
	int _year;
	int _month;
	int _day;
};

struct PDateLess
{
	bool operator()(const Date* d1, const Date* d2)
	{
		return *d1 < *d2;
	}
};

struct PDateGreater
{
	bool operator()(const Date* d1, const Date* d2)
	{
		return *d1 > *d2;
	}
};



void TestPriorityQueue()
{
	// 大堆，需要用户在自定义类型中提供<的重载
	priority_queue<Date> q1;
	q1.push(Date(2018, 10, 29));
	q1.push(Date(2018, 10, 28));
	q1.push(Date(2018, 10, 30));
	cout << q1.top() << endl;

	// 如果要创建小堆，需要用户提供>的重载
	priority_queue<Date, vector<Date>, Lewis::greater<Date>> q2;
	q2.push(Date(2018, 10, 29));
	q2.push(Date(2018, 10, 28));
	q2.push(Date(2018, 10, 30));
	cout << q2.top() << endl;


	// 大堆
	priority_queue<Date*, vector<Date*>, PDateLess> q3;
	q3.push(new Date(2018, 10, 29));
	q3.push(new Date(2018, 10, 28));
	q3.push(new Date(2018, 10, 30));
	cout << *q3.top() << endl;

	// 小堆
	priority_queue<Date*, vector<Date*>, PDateGreater> q4;
	q4.push(new Date(2018, 10, 29));
	q4.push(new Date(2018, 10, 28));
	q4.push(new Date(2018, 10, 30));
	cout << *q4.top() << endl;
}


int main()
{
	TestPriorityQueue();

	return 0;
}