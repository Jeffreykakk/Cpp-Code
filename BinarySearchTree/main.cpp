#include "BinarySearchTree.h"

using namespace Jeffrey;

void test1()
{
    BSTree<int> t;
    int a[] = {8, 4, 2, 5, 7, 3, 5, 10};
    for (auto &e : a)
        t.insertR(e);
    t.Inorder();

    BSTree<int> t1 = t;
    for (auto &e : a)
        t.erase(e);
    t1 = t;
    t1.Inorder();
}

int main()
{
    test1();
    system("pause");
    return 0;
}