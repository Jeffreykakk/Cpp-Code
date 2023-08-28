#include "AVLTree.h"

using namespace Jeffrey;

void test1()
{
    int a[] = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
    AVLTree<int, int> t1;
    t1.Insert(make_pair(4, 1));
    t1.Insert(make_pair(2, 1));
    t1.Insert(make_pair(6, 1));
    t1.Insert(make_pair(1, 1));
    t1.Insert(make_pair(3, 1));
    t1.Insert(make_pair(5, 1));
    t1.Insert(make_pair(15, 1));
    t1.Insert(make_pair(7, 1));
    t1.Insert(make_pair(16, 1));
    t1.Insert(make_pair(14, 1));
    t1.Inorder();
    cout << t1.isBalanced() << endl;
    for(auto& e:a)
        cout << t1.Find(e) << " ";
    cout << endl;
}

void test2()
{
    size_t N = 10000;
    AVLTree<int, int> t1;
    for (size_t i = 0; i < N; ++i)
    {
        int x = rand();
        if (x + i == 16840)
        {
            int a = 1;
        }
        t1.Insert(make_pair(x + i, i));
    }
    cout << t1.isBalanced() << endl;
}

int main()
{
    test1();
    system("pause");
    return 0;
}