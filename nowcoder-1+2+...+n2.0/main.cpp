#include <iostream>

// 求1+2+3+...+n
// 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句

using namespace std;

class Sum
{
public:
    Sum()
    {
        sum += i;
        i++;
    }
    int GetSum()
    {
        return sum;
    }

private:
    static int sum;
    static int i;
};

int Sum::sum = 0;
int Sum::i = 1;

class Solution
{
public:
    int Sum_Solution(int n)
    {
        Sum a[n];
        return a[0].GetSum();
    }
};

int main()
{
    int n = 0;
    cin >> n;
    cout << Solution().Sum_Solution(n) << endl;
    return 0;
}