#include <iostream>
using namespace std;
class Date
{
public:
    int _year;
    int _month;
    int _day;
    int getMonthDay(int year, int month)
    {
        int MonthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            MonthDay[2]++;
        return MonthDay[month];
    }
    Date(int year, int month, int day)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    Date(const Date& d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    Date& operator+=(int day)
    {
        _day += day;
        while (_day > getMonthDay(_year, _month))
        {
            _day -= getMonthDay(_year, _month);
            _month++;
            if (_month > 12)
                _month = 1, _year++;
        }
        return *this;
    }
};

int main()
{
    int t, y, m, d, add;
    cin >> t;
    while (t--)
    {
        cin >> y >> m >> d >> add;
        Date d1(y, m, d);
        d1 += add;
        printf("%d-%02d-%02d\n", d1._year, d1._month, d1._day);
    }
    return 0;
}











