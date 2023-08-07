#include <deque>
#include <iostream>
#include <stdbool.h>
#include <windows.h>
using namespace std;

namespace Jeffrey
{
    template <class T, class Container = deque<T>>
    class queue
    {
    public:
        void push(const T &x)
        {
            _con.push_back(x);
        }
        void pop()
        {
            _con.pop_front();
        }
        size_t size() const
        {
            return _con.size();
        }
        bool empty() const
        {
            return _con.empty();
        }
        void swap(queue<T, Container> &q)
        {
            _con.swap(q._con);
        }
        T &front()
        {
            return _con[0];
        }
        const T &front() const
        {
            return _con[0];
        }
        T &back()
        {
            return _con[size() - 1];
        }
        const T &back() const
        {
            return _con[size() - 1];
        }

    private:
        Container _con;
    };

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
        while(!q1.empty())
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
};