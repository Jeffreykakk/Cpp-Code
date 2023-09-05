#include "BloomFilter.h"
#include <time.h>

void test1()
{
    vector<string> v1 = {
        "apple",
        "school",
        "string",
        "vector",
        "banana",
        "map",
        "set",
        "bitset"};
    vector<string> v2 = {
        "apple",
        "school1",
        "string1",
        "vector1",
        "banana1",
        "map1",
        "set1",
        "bitset1"};
    Jeffrey::BloomFilter<300> bf;
    for (auto &e : v1)
        bf.set(e);
    for (auto &e : v2)
        cout << bf.test(e) << " ";
    cout << endl;
}

void test2()
{
    srand(time(0));
    const size_t N = 100000;
    Jeffrey::BloomFilter<N> bf;

    vector<string> v1;
    string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";

    for (size_t i = 0; i < N; ++i)
        v1.push_back(url + to_string(1234 + i));

    for (auto &str : v1)
        bf.set(str);

    // 相似
    vector<string> v2;
    for (size_t i = 0; i < N; ++i)
    {
        string url = "http://www.cnblogs.com/-clq/archive/2021/05/31/2528153.html";
        url += to_string(rand() + i);
        v2.push_back(url);
    }

    size_t n2 = 0;
    for (auto &str : v2)
    {
        if (bf.test(str))
            ++n2;
    }
    cout << "相似字符串误判率:" << (double)n2 / (double)N << endl;

    vector<string> v3;
    for (size_t i = 0; i < N; ++i)
    {
        string url = "zhihu.com";
        url += std::to_string(rand() + i);
        v3.push_back(url);
    }

    size_t n3 = 0;
    for (auto &str : v3)
    {
        if (bf.test(str))
            ++n3;
    }
    cout << "不相似字符串误判率:" << (double)n3 / (double)N << endl;
}

int main()
{
    test2();
    system("pause");
    return 0;
}