#include <iostream>

using namespace std;

//范围for遍历数组
//范围for的使用条件：for循环迭代的范围必须确定

int main()
{
    int arr[]={1,2,3,4,5};
    for(auto& e : arr)
    e *= 2;
    for(auto e : arr)
    cout << e << " ";
    return 0;
}
