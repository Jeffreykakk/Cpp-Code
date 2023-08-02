#include <string>
#include <windows.h>
#include "mystring.h"

void test_string()
{
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    cout << s1 << endl;
    cout << s2 << endl;
}

int main()
{
    Jeffrey::test_string();
    cout << "------------" << endl;
    ::test_string();

    system("pause");
    return 0;
}