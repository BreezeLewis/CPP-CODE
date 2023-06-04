#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
class Date {
public:
    string date;
    int _year;
    int _month;
    int _day;
    Date(string date) {
        string y;
        for (int i = 0; i < 4; i++)
            y += date[i];
        _year = stoi(y);
        string m;
        for (int i = 4; i < 6; i++)
            m += date[i];
        _month = stoi(m);
        string d;
        for (int i = 6; i < 8; i++)
            d += date[i];
        _day = stoi(d);
    }
    Date& operator--() {
        *this -= 1;
        return *this;
    }
    Date& operator-=(int day) {
        //使用GetMonthDay时确保年和月是你想要的
        _day -= day;
        while (_day < 0) {
            _month--;
            if (_month < 1)
                _month = 12, _year--;
            _day += GetMonthDay(_year, _month);
        }
        return *this;
    }
    int GetMonthDay(int year, int month) {
        int MonthDay[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //1-12月的天数
        int flag = 0;//标记闰年
        if (month == 2 && (year % 400 == 0 || (year % 4 == 0 &&
            year % 100 != 0)))//如果是闰年的2月，才将flag置1
            flag = 1;
        return MonthDay[month] + flag;
    }
    bool operator>(const Date& d)
    {
        if (_year > d._year)
            return true;
        else if (_year < d._year)
            return false;
        else { //年相等
            if (_month > d._month)
                return true;
            else if (_month < d._month)
                return false;
            else { //年月相等
                if (_day > d._day)
                    return true;
                else
                    return false;
            }
        }
    }
};
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    Date d1(s1);
    Date d2(s2);
    int ans = 1;
    if (d1 > d2)
        swap(d1, d2);

    while (d2 > d1)
    {
        --d2;
        ans++;
    }
    cout << ans << endl;
    return 0;
}


















