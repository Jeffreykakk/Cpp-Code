#include "HashTable.h"

void test1()
{
    Jeffrey::HashTable<int, int> ht;
    ht.insert(make_pair(1, 1));
    ht.insert(make_pair(11, 1));
    ht.insert(make_pair(5, 1));
    ht.insert(make_pair(25, 1));
    ht.insert(make_pair(6, 1));
    ht.insert(make_pair(4, 1));
    ht.insert(make_pair(14, 1));
    ht.Print();
    ht.insert(make_pair(8, 1));
    ht.Print();
    ht.erase(1);
    ht.erase(11);
    ht.erase(1);
    ht.Print();
}

void test2()
{
    Jeffrey::HashTable<string, string> ht;
    ht.insert(make_pair("string", "字符串"));
    ht.insert(make_pair("sort", "排序"));
    ht.insert(make_pair("hash", "哈希"));
    ht.insert(make_pair("left", "左边"));
    ht.insert(make_pair("right", "右边"));
    ht.insert(make_pair("vector", "向量"));
    ht.insert(make_pair("hello", "你好"));
    ht.Print();
    ht.insert(make_pair("world", "世界"));
    ht.Print();
}

int main()
{
    test2();
    system("pause");
    return 0;
}