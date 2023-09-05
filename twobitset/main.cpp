#include <iostream>
#include <bitset>
#include <stdbool.h>
#include <windows.h>

using namespace std;

// 大量无符号整型数据，如何从中快速找到出现次数不超过两次的整数
// 0 0 出现 0 次
// 0 1 出现 1 次
// 1 0 出现 2 次
// 1 1 出现 2 次以上

template <size_t N>
class twobitset
{
public:
    void set(size_t n)
    {
        if (_bt1->test(n) == false && _bt2->test(n) == false)
            _bt2->set(n);
        else if (_bt1->test(n) == false && _bt2->test(n) == true)
        {
            _bt1->set(n);
            _bt2->reset(n);
        }
        else if (_bt1->test(n) == true && _bt2->test(n) == false)
            _bt2->set(n);
        else
            return;
    }
    bool testbelowtwo(size_t n)
    {
        if (_bt1->test(n) == false && _bt2->test(n) == false)
            return true;
        else if (_bt1->test(n) == false && _bt2->test(n) == true)
            return true;
        else if (_bt1->test(n) == true && _bt2->test(n) == false)
            return true;
        else
            return false;
    }

private:
    bitset<N> *_bt1 = new bitset<N>;
    bitset<N> *_bt2 = new bitset<N>;
};

int main()
{
    int arr[] = {0, 0, 1, 2, 3, 3, 3, 4, 4, 4, 5, 6, 7, 8, 9, 9, 9};
    twobitset<0xffffffff> twobt;
    for (auto &e : arr)
        twobt.set(e);
    for (size_t i = 0; i < 10; i++)
    {
        if (twobt.testbelowtwo(i))
            cout << i << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}