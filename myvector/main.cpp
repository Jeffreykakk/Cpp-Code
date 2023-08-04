#include <vector>
#include <windows.h>
#include "myvector.h"

void test_vector1()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    vector<int> v2;
    for (size_t i = 0; i < v1.size(); i++)
        cout << v1[i] << ' ';
    cout << endl;
    v2 = v1;
    for (size_t i = 0; i < v2.size(); i++)
        cout << v2[i] << ' ';
    cout << endl;
}
void test_vector2()
{
    vector<vector<int>> v(5);
    for (auto &e : v)
        cout << e.capacity() << ' ';
    cout << endl;
}
void test_vector3()
{
    list<int> l;
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    l.push_back(8);
    l.push_back(9);
    l.push_back(10);
    vector<int> v(l.begin(), l.end());
    for (auto &e : v)
        cout << e << ' ';
    cout << endl;
}
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> vv;
        vv.resize(numRows);

        for (size_t i = 0; i < vv.size(); ++i)
        {
            vv[i].resize(i + 1, 0);
            vv[i].front() = vv[i].back() = 1;
        }

        for (size_t i = 0; i < vv.size(); ++i)
        {
            for (size_t j = 0; j < vv[i].size(); ++j)
            {
                if (vv[i][j] == 0)
                {
                    vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
                }
            }
        }

        for (size_t i = 0; i < vv.size(); ++i)
        {
            for (size_t j = 0; j < vv[i].size(); ++j)
            {
                cout << vv[i][j] << " ";
            }
            cout << endl;
        }

        return vv;
    }
};
void test_vector4()
{
    vector<vector<int>> ret = Solution().generate(5);
}
int main()
{
    // Jeffrey::test_vector2();
    // cout << "------------" << endl;
    // ::test_vector2();
    Jeffrey::test_vector4();
    cout << "------------" << endl;
    ::test_vector4();
    system("pause");
    return 0;
}