#include <string>
#include <iostream>
#include <windows.h>
using namespace std;

// 给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开
// 返回字符串中最后一个单词的长度

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int end = s.size() - 1;
        while (s[end] == ' ')
            end--;
        int pos = s.rfind(' ', end);
        if (pos == string::npos)
            return end + 1;
        else
            return end - pos;
    }
};
int main()
{
    string s("   fly me   to   the moon  ");
    cout << Solution().lengthOfLastWord(s) << endl;
    system("pause");
    return 0;
}