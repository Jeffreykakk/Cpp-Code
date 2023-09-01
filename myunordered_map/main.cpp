#include "myunordered_map.h"
#include <unordered_map>

void test2()
{
    unordered_map<string, int> countmap;
    const char *arr[] = {"apple", "pine", "pine", "banana", "apple"};
    for (auto &e : arr)
        countmap[e]++;
    for (auto &e : countmap)
        cout << e.first << ":" << e.second << endl;
}

int main()
{
    // test2();
    // cout << "----------------------------------------------" << endl;
    Jeffrey::test1();
    system("pause");
    return 0;
}