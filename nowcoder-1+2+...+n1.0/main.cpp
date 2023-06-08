#include <iostream>

//求1+2+3+...+n
//要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句

using namespace std;
int sum = 0;
int i = 1;

class Sum
{
public:
    Sum()
    {
        sum += i;
        i++;
    }
};

class Solution
{
public:
    int Sum_Solution(int n)
    {
        Sum a[n];
        return sum;
    }
};

int main()
{
    int n = 0;
    Solution s;
    cin >> n;
    cout << s.Sum_Solution(n) << endl;
    return 0;
}