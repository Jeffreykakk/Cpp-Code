#include <iostream>

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
    Date d1(2023,6,5);
    Date d2;
    d1.DatePrint();
    d2.DatePrint();
    return 0;
}