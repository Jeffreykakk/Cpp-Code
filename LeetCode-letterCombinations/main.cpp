#include <vector>
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

class Solution
{
    const char *NumToStr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    void CombineStr(vector<string> &v, string str, string &digits, int i)
    {
        if (i == digits.size())
        {
            v.push_back(str);
            return;
        }
        int num = digits[i] - '0';
        string s = NumToStr[num];
        for (auto &e : s)
            CombineStr(v, str + e, digits, i + 1);
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> v;
        if (digits.size() == 0)
            return v;
        string str;
        CombineStr(v, str, digits, 0);
        return v;
    }
};

int main()
{
    auto v = Solution().letterCombinations("23");
    for(auto& e:v)
        cout << e << ' ';
    cout << endl;
    system("pause");
    return 0;
}