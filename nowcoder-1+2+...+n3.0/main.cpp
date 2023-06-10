#include <iostream>

// 求1+2+3+...+n
// 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句

using namespace std;

class Solution
{
class Sum
{
public:
    Sum()
    {
        sum += i;
        i++;
    }
};
public:
    int Sum_Solution(int n)
    {
        Sum a[n];
        return sum;
    }
private:
    static int sum;
    static int i;
};

int Solution::sum = 0;
int Solution::i = 1;

int main()
{
    int n = 0;
    cin >> n;
    cout << Solution().Sum_Solution(n) << endl;
    return 0;
}