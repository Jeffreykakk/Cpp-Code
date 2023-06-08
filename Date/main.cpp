#include <iostream>
#include <stdbool.h>
#include <assert.h>
#include <windows.h>
using namespace std;

class Date
{
    friend ostream &operator<<(ostream &out, const Date &d)
    {
        out << d._year << '-' << d._month << '-' << d._day;
        return out;
    }

    friend istream &operator>>(istream &in, Date &d)
    {
        in >> d._year >> d._month >> d._day;
        assert(d.CheckDate());
        return in;
    }

public:
    // 成员函数

    Date(int year = 1, int month = 1, int day = 1) // 默认构造函数，用Date创建实例后自动调用，用来初始化实例
    {                                              // 缺省参数：当创建实例没有给具体要初始化的日期，则使用指定的形参
        _year = year;
        _month = month;
        _day = day;
        assert((*this).CheckDate());
    }

    bool IsLeap() const
    {
        return _year % 4 == 0 && _year % 100 != 0 || _year % 400 == 0;
    }

    bool CheckDate()
    {
        if (_month > 0 && _month < 13 && _day >= 1 && _day <= (*this).GetMonthDay())
            return true;
        else
            return false;
    }

    int GetMonthDay() const
    {
        static int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (_month == 2 && (*this).IsLeap())
            return 29;
        else
            return days[_month];
    }

    bool operator==(const Date &d) const
    {
        return _year == d._year && _month == d._month && _day == d._day;
    }

    bool operator!=(const Date &d) const
    {
        return !(*this == d);
    }

    bool operator>(const Date &d) const
    {
        if (_year > d._year)
            return true;
        else if (_year == d._year && _month > d._month)
            return true;
        else if (_year == d._year && _month == d._month && _day > d._day)
            return true;
        else
            return false;
    }

    bool operator>=(const Date &d) const
    {
        return *this > d || *this == d;
    }

    bool operator<(const Date &d) const
    {
        return !(*this >= d);
    }

    bool operator<=(const Date &d) const
    {
        return !(*this > d);
    }

    Date operator+(int day) const
    {
        if (day < 0)
            return *this - (-day);
        else
        {
            Date copy = *this;
            return copy += day;
        }
    }

    Date &operator+=(int day)
    {
        if (day < 0)
            return *this -= (-day);
        else
        {
            _day += day;
            while (_day > (*this).GetMonthDay())
            {
                _day -= (*this).GetMonthDay();
                _month++;
                if (_month == 13)
                {
                    _year++;
                    _month = 1;
                }
            }
            return *this;
        }
    }

    Date operator-(int day) const
    {
        if (day < 0)
            return *this + (-day);
        else
        {
            Date copy = *this;
            copy -= day;
            return copy;
        }
    }

    Date &operator-=(int day)
    {
        if (day < 0)
            return *this += (-day);
        else
        {
            _day -= day;
            while (_day < 1)
            {
                _month--;
                if (_month == 0)
                {
                    _month = 12;
                    _year--;
                }
                _day += (*this).GetMonthDay();
            }
            return *this;
        }
    }

    Date &operator++()
    {
        return *this += 1;
    }

    Date operator++(int)
    {
        Date tmp = *this;
        *this += 1;
        return tmp;
    }

    Date &operator--()
    {
        return *this -= 1;
    }

    Date operator--(int)
    {
        Date tmp = *this;
        *this -= 1;
        return tmp;
    }

    int operator-(Date &d)
    {
        int flag = 1;
        Date max = *this;
        Date min = d;
        if (*this < d)
        {
            max = d;
            min = *this;
            flag = -1;
        }
        int n = 0;
        while (min != max)
        {
            ++min;
            ++n;
        }
        return n * flag;
    }

    void Print() const
    {
        cout << _year << '-' << _month << '-' << _day << endl;
    }

private:
    // 成员变量
    int _year;
    int _month;
    int _day;
};

void Menu()
{
    cout << "*****************************" << endl;
    cout << "******  1. 日期加减天数 ******" << endl;
    cout << "******   2.日期减日期   ******" << endl;
    cout << "********   -1. 退出  ********" << endl;
    cout << "*****************************" << endl;
}

int main()
{
    int option = 0;
    do
    {
        Menu();
        Date d1, d2;
        int day = 0;
        cout << "请选择：";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "请依次输入日期和天数：" << endl;
            cin >> d1 >> day;
            cout << (d1 + day) << endl;
            break;
        case 2:
            cout << "请依次输入日期：" << endl;
            cin >> d1 >> d2;
            cout << (d1 - d2) << endl;
            break;
        case -1:
            break;
        default:
            cout << "输入错误，请重新输入" << endl;
            break;
        }
    } while (option != -1);
    system("pause");
    return 0;
}