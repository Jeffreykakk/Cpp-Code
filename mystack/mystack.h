#include <deque>
#include <iostream>
#include <stdbool.h>
#include <windows.h>
using namespace std;

namespace Jeffrey
{
    template <class T, class Container = deque<T>>
    class stack
    {
    public:
        void push(const T &x)
        {
            _con.push_back(x);
        }
        void pop()
        {
            _con.pop_back();
        }
        size_t size() const
        {
            return _con.size();
        }
        bool empty() const
        {
            return _con.empty();
        }
        void swap(stack<T, Container> &st)
        {
            _con.swap(st._con);
        }
        T &top()
        {
            return _con[size() - 1];
        }
        const T &top() const
        {
            return _con[size() - 1];
        }

    private:
        Container _con;
    };

    void test_stack()
    {
        stack<int> st1;
        stack<int> st2;
        st1.push(1);
        st1.push(2);
        st1.push(3);
        st1.push(4);
        st1.push(5);
        st2.push(3);
        st2.push(5);
        st2.push(8);
        st1.swap(st2);
        while(!st1.empty())
        {
            cout << st1.top() << ' ';
            st1.pop();
        }
        cout << endl;
        while (!st2.empty())
        {
            cout << st2.top() << ' ';
            st2.pop();
        }
        cout << endl;
    }
};