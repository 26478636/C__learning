// 自己复制自己
#include <iostream>

using namespace std;

class base_style
{
public:
    // 创建自己克隆自己的接口
    virtual base_style *clone() = 0;
    virtual void print() = 0;
};

class A_style : public base_style
{
public:
    base_style *clone()
    {
        A_style *mid = new A_style(*this);
        return mid; // 这里实现的是拷贝构造
    }
    void print()
    {
        if (clone())
            cout << "子类打印成功" << endl;
        else
            cout << "打印不成功" << endl;
    }
};

class AA_style : public A_style
{
public:
    base_style *clone()
    {
        AA_style *mid = new AA_style(*this);
        return mid; // 这里实现的是拷贝构造
    }
    void print()
    {
        if (clone())
            cout << "孙类打印成功" << endl;
        else
            cout << "打印不成功" << endl;
    }
};

int main()
{
    A_style *_a = new A_style();    // 子类
    AA_style *_aa = new AA_style(); // 孙类
    // 克隆子类
    auto _a_1 = _a->clone();
    auto _aa_1 = _aa->clone();

    _a->print();
    _aa->print();
    return 0;
}