#include "RBTree.h"

using namespace Jeffrey;

void test1()
{
    RBTree<int, int> t1;
    t1.Insert(make_pair(1, 1));
    t1.Insert(make_pair(9, 1));
    t1.Insert(make_pair(3, 1));
    t1.Insert(make_pair(8, 1));
    t1.Insert(make_pair(4, 1));
    t1.Insert(make_pair(15, 1));
    t1.Insert(make_pair(5, 1));
    t1.Insert(make_pair(2, 1));
    t1.Insert(make_pair(7, 1));
    t1.Insert(make_pair(8, 1));
    t1.Insert(make_pair(10, 1));
    t1.Insert(make_pair(14, 1));
    t1.Inorder();
    cout << t1.IsRBTree() << endl;
    for (auto &e : t1)
        cout << e.first << ":" << e.second << endl;
}

void test2()
{
    RBTree<int, int> t1;
    srand(time(0));
    int N = 10000;
    for (int i = 0; i < N; i++)
    {
        int x = rand() + i;
        t1.Insert(make_pair(x, i));
    }
    t1.Inorder();
    cout << t1.IsRBTree() << endl;
}

int main()
{
    test1();
    system("pause");
    return 0;
}