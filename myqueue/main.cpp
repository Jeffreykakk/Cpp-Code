#include "myqueue.h"
#include <queue>

void test_queue()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    queue<int> q2;
    q2.push(5);
    q2.push(6);
    q2.push(7);
    q2.push(8);
    while (!q1.empty())
    {
        cout << q1.front() << ' ';
        q1.pop();
    }
    cout << endl;
    while (!q2.empty())
    {
        cout << q2.front() << ' ';
        q2.pop();
    }
    cout << endl;
}

int main()
{
    Jeffrey::test_queue();
    cout << "--------------------" << endl;
    ::test_queue();
    system("pause");
    return 0;
}