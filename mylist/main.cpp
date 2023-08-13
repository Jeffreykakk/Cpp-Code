#include "mylist.h"
#include <list>

void test_list()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_front(0);
    l.push_front(-1);
    l.insert(find(l.begin(), l.end(), 4), 3);
    l.insert(find(l.begin(), l.end(), 3), 0);
    l.pop_back();
    l.pop_front();
    l.pop_back();
    l.pop_front();
    l.pop_back();
    l.pop_back();
    l.pop_front();
    l.erase(find(l.begin(), l.end(), 2));
    l.push_front(1);
    l.erase(find(l.begin(), l.end(), 0));
    
}

void test_list_reverse_iterator()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    auto rit = l.rbegin();
    while (rit != l.rend())
    {
        cout << *rit << " ";
        rit++;
    }
    cout << endl;
}

int main()
{
    Jeffrey::test_list_reverse_iterator();
    cout << "--------------------" << endl;
    ::test_list_reverse_iterator();
    system("pause");
    
    return 0;
}