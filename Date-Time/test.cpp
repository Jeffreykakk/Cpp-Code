#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

class Time
{
public:
    Time(int hour = 1, int minute = 1, int second = 1)
    :_hour(hour),
    _minute(minute),
    _second(second)
    {
    }
    void Print()
    {
        printf("%02d:%02d:%02d\n", _hour, _minute, _second);
    }
private:
    int _hour;
    int _minute;
    int _second;
};

class Date
{
public:
    //初始化列表
    Date(int year = 1, int month = 1, int day = 1, int hour = 1, int minute = 1, int second = 1)
        : _year(year),
          _month(month),
          _day(day),
          _t(hour, minute, second)
    {
    }
    void Print()
    {
        cout << _year << '-' << _month << '-' << _day << ' ';
        _t.Print();
    }

private:
    int _year;
    int _month;
    int _day;
    Time _t;
};

int main()
{
    Date d1(2023,6,10,11,40,59);
    d1.Print();
    system("pause");
    return 0;
}