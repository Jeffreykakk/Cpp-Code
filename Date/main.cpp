#include <iostream>
#include <stdbool.h>
#include <windows.h>
using namespace std;

class Date
{
public:
    //成员函数
    
    Date(int year=1,int month=1,int day=1)      //默认构造函数，用Date创建实例后自动调用，用来初始化实例
    {                                           //缺省参数：当创建实例没有给具体要初始化的日期，则使用指定的形参
        _year=year;     
        _month=month;
        _day=day;
    }
    bool IsLeap()
    {
        return _year%4==0 && _year%100!=0 || _year %400==0;
    }
    int GetMonthDay()
    {
        static int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(_month==2 && (*this).IsLeap())
        return 29;
        else
        return days[_month];
    }
    bool operator==(const Date& d)
    {
        return _year==d._year && _month==d._month && _day==d._day;
    }
    Date operator+(int day)
    {
        Date copy=*this;
        copy._day+=day;
        while(copy._day>copy.GetMonthDay())
        {
            copy._day-=copy.GetMonthDay();
            copy._month++;
            if(copy._month==13)
            {
                copy._year++;
                copy._month=1;
            }
        }
        return copy;
    }
    Date& operator+=(int day)
    {
        _day+=day;
        while(_day>(*this).GetMonthDay())
        {
            _day-=(*this).GetMonthDay();
            _month++;
            if(_month==13)
            {
                _year++;
                _month=1;
            }
        }
        return *this;
    }
    void DatePrint()
    {
        cout << _year << '-' << _month << '-' << _day << endl;
    }
private:
    //成员变量
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date d1(2022,7,23);
    Date d2=d1+50;
    d1+=50;
    d1.DatePrint();
    d2.DatePrint();
    system("pause");
    return 0;
}