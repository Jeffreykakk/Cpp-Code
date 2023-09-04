#include <string>
#include <windows.h>
#include "mystring.h"

void test1()
{
    string s1 = "abcd";
    s1.append("efghijk");
    const string s2 = "cccccc";
    s1.append(s2);
    s1.push_back('a');
    cout << s1.append(5, '6').c_str() << endl;
    cout << s1.insert(2, "8888").c_str() << endl;
    cout << s1.insert(2, s2).c_str() << endl;
    cout << s1.insert(2, 3, '3').c_str() << endl;
    cout << s1.erase(3, 3).c_str() << endl;
    s1.clear();
    s1 += "abcd";
    s1 += s2;
    s1 += 'h';
    cout << s1.c_str() << endl;
    cout << s1.find(s2) << endl;
    string s3 = s1.substr(3, 2);
    cout << s3.c_str() << endl;
}
void test2()
{
    string s = "abcdef";
    cout << s.substr(2, 2).c_str() << endl;
    s.resize(10, 'c');
    cout << s.c_str() << endl;
}
void test3()
{
    string s1 = "abcd";
    string s2 = "1234";
    cout << s1 << s2 << endl;
}

void test4()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    cout << s1 << endl;
    cout << s2 << endl;
}

int main()
{
    Jeffrey::test4();
    cout << "------------" << endl;
    ::test4();

    system("pause");
    return 0;
}