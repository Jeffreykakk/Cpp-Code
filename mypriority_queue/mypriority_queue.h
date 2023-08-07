#include <vector>
#include <iostream>
#include <stdbool.h>
#include <windows.h>
using namespace std;

namespace Jeffrey
{
    template <class T>
    struct less
    {
    public:
        bool operator()(const T &x1, const T &x2)
        {
            return x1 < x2;
        }
    };
    template <class T>
    struct greater
    {
    public:
        bool operator()(const T &x1, const T &x2)
        {
            return x1 > x2;
        }
    };

    template <class T, class Container = vector<T>, class Compare = less<int>>
    class priority_queue
    {
    private:
        Container _con;
        void adjuest_up(size_t child)
        {
            size_t parent = (child - 1) / 2;
            while (child > 0)
            {
                if (Compare()(_con[parent], _con[child]))
                {
                    ::swap(_con[child], _con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                    break;
            }
        }
        void adjuest_down(size_t parent)
        {
            size_t child = parent * 2 + 1;
            while (child < size())
            {
                if (child + 1 < size() && Compare()(_con[child], _con[child + 1]))
                    child++;
                if (Compare()(_con[parent], _con[child]))
                {
                    ::swap(_con[parent], _con[child]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                    break;
            }
        }

    public:
        priority_queue()
        {
        }
        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                _con.push_back(*first);
                first++;
            }
            for (int i = (size() - 1 - 1) / 2; i >= 0; i--)
                adjuest_down(i);
        }
        void push(const T &x)
        {
            _con.push_back(x);
            adjuest_up(size() - 1);
        }
        void pop()
        {
            ::swap(_con[0], _con[size() - 1]);
            _con.pop_back();
            adjuest_down(0);
        }
        size_t size() const
        {
            return _con.size();
        }
        bool empty() const
        {
            return _con.empty();
        }
        void swap(priority_queue<T, Container> &pq)
        {
            _con.swap(pq._con);
        }
        const T &top() const
        {
            return _con[0];
        }
    };

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
};