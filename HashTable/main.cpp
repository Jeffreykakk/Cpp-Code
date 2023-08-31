#include "HashTable.h"

void test1()
{
    Jeffrey::HashTable<int, int> ht;
    ht.insert(make_pair(1, 1));
    ht.insert(make_pair(11, 1));
    ht.insert(make_pair(3, 1));
    ht.insert(make_pair(12, 1));
    ht.insert(make_pair(15, 1));
    ht.insert(make_pair(5, 1));
    ht.insert(make_pair(7, 1));
    ht.insert(make_pair(6, 1));
    ht.insert(make_pair(8, 1));
    ht.insert(make_pair(33, 1));
    ht.print();
    ht.insert(make_pair(18, 1));
    cout << "---------------------------------------------------------" << endl;
    ht.print();
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
    ht.insert(make_pair("time", "时间"));
    ht.insert(make_pair("table", "表"));
    ht.insert(make_pair("map", "地图"));
    ht.print();
    ht.insert(make_pair("world", "世界"));
    cout << "---------------------------------------------------------" << endl;
    ht.print();
    cout << ht.BucketSize() << endl;
    cout << ht.TableSize() << endl;
    cout << ht.size() << endl;
    cout << ht.MaxBucketLength() << endl;
}

void test3()
{
    Jeffrey::HashTable<string, string> ht;
    ht.insert(make_pair("string", "字符串"));
    ht.insert(make_pair("sort", "排序"));
    ht.insert(make_pair("hash", "哈希"));
    ht.insert(make_pair("left", "左边"));
    ht.insert(make_pair("right", "右边"));
    ht.insert(make_pair("vector", "向量"));
    ht.insert(make_pair("hello", "你好"));
    ht.insert(make_pair("time", "时间"));
    ht.insert(make_pair("table", "表"));
    ht.insert(make_pair("map", "地图"));
    ht.insert(make_pair("world", "世界"));
    ht.print();
    cout << "---------------------------------" << endl;
    auto it = ht.begin();
    while (it != ht.end())
    {
        cout << it->first << ":" << it->second << endl;
        ++it;
    }
    cout << "---------------------------------" << endl;
    for (auto &e : ht)
        cout << e.first << ":" << e.second << endl;
}

int main()
{
    test3();
    system("pause");
    return 0;
}