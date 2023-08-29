#include "mymap.h"
#include <map>

void test()
{
    const char *s[] = {"apple", "banana", "apple", "banana", "pine"};
    std::map<string, int> m;
    for (auto &e : s)
        m[e]++;
    for (auto &e : m)
        cout << e.first << ":" << e.second << endl;
}

int main()
{
    ::test();
    cout << "---------------------------------" << endl;
    Jeffrey::test();

    system("pause");
    return 0;
}