#include "mypriority_queue.h"
#include <queue>
#include <functional>

void test_priority_queue1()
{
    priority_queue<int> pq1;
    pq1.push(2);
    pq1.push(1);
    pq1.push(5);
    pq1.push(3);
    pq1.push(4);
    pq1.push(2);
    priority_queue<int> pq2;
    pq2.push(8);
    pq2.push(7);
    pq2.push(5);
    pq2.push(6);
    pq2.push(7);
    pq2.push(10);
    while (!pq1.empty())
    {
        cout << pq1.top() << ' ';
        pq1.pop();
    }
    cout << endl;
    while (!pq2.empty())
    {
        cout << pq2.top() << ' ';
        pq2.pop();
    }
    cout << endl;
}
void test_priority_queue2()
{
    vector<int> v{5, 3, 5, 8, 9, 0, 2, 3, 1, 5, 6};
    priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());
    while (!pq.empty())
    {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << endl;
}

int main()
{
    Jeffrey::test_priority_queue2();
    cout << "--------------------" << endl;
    ::test_priority_queue2();
    system("pause");
    return 0;
}