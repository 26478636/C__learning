#include <iostream>
#include <memory>
using namespace std;

int main()
{
    int *a = new int{123}; // 初始化一个指针
    unique_ptr<int> p0;    // int 为指针类型。。未经过初始化
    unique_ptr<int> p1 = make_unique<int>(123);
    unique_ptr<int> p2(new int{123});

    if (p0)
    {
        cout << "经过初始化" << endl;
    }
    else
    {
        cout << "未经初始化" << endl;
    }

    auto a1 = p1.get();

    cout << *a << endl;
    cout << *p1 << endl;
    cout << *p2 << endl;

    p1.swap(p0);
    cout << return 0;
}