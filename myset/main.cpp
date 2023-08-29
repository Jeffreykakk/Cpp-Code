#include "myset.h"

void test()
{
    set<int> s;
    s.Insert(1);
    s.Insert(4);
    s.Insert(2);
    s.Insert(3);
    s.Insert(8);
    s.Insert(5);
    s.Insert(6);
    s.Insert(7);
    for (auto &e : s)
        cout << e << " ";
    cout << endl;
}

int main()
{
    test();
    system("pause");
    return 0;
}