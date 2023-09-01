#include "myunordered_set.h"
#include <unordered_set>

void test()
{
    unordered_set<int> s;
    s.insert(12);
    s.insert(2);
    s.insert(22);
    s.insert(3);
    s.insert(13);
    s.insert(2);
    s.insert(7);
    s.insert(4);
    for (auto &e : s)
        cout << e << " ";
    cout << endl;
}

int main()
{
    test();
    cout << "---------------------------------------------" << endl;
    Jeffrey::test();
    system("pause");
    return 0;
}