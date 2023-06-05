#include <iostream>

namespace Jeffrey
{
    void Swap(char& a,char& b)
    {
        char tmp=a;
        a=b;
        b=tmp;
    }
    void Swap(int& a,int& b)
    {
        int tmp=a;
        a=b;
        b=tmp;
    }
    void Swap(double& a,double& b)
    {
        double tmp=a;
        a=b;
        b=tmp;
    }
}

using namespace Jeffrey;
using namespace std;

int main()
{
    char ch1='a',ch2='b';
    int a=10,b=20;
    double c=2.5,d=3.8;
    Swap(ch1,ch2);
    Swap(a,b);
    Swap(c,d);
    cout << ch1 << '\t' << ch2 << endl;
    cout << a << '\t' << b << endl;
    cout << c << '\t' << d << endl;
    return 0;
}