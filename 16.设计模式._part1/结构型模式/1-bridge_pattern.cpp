// 将软件嵌入到手机里
#include <iostream>

using namespace std;

// 软件基类
class base_soft
{
public:
    // 软件运行接口类
    virtual void run_soft() = 0;
};
// 软件子类
class A_soft : public base_soft
{
public:
    void run_soft()
    {
        cout << "软件A输出" << endl;
    }
};
class B_soft : public base_soft
{
public:
    void run_soft()
    {
        cout << "软件B输出" << endl;
    }
};

// 手机基类
class base_phone
{
protected:
    base_soft *_base_soft;

public:
    // 默认构造
    base_phone() : _base_soft(nullptr) {}
    // 相当于有参构造
    void installsoft(base_soft *_soft)
    {
        _base_soft = _soft;
    }
    // 接口函数
    virtual void begin_soft() = 0;
};
// 手机子类
class A_phone : public base_phone
{
public:
    void begin_soft()
    {
        if (_base_soft)
        {
            cout << "执行软件程序" << endl;
            _base_soft->run_soft();
        }
        else
        {
            cout << "执行软件程序失败" << endl;
        }
    }
};

class B_phone : public base_phone
{
public:
    void begin_soft()
    {
        if (_base_soft)
        {
            cout << "执行软件程序" << endl;
            _base_soft->run_soft();
        }
        else
        {
            cout << "执行软件程序失败" << endl;
        }
    }
};

int main()
{
    // 软件new
    A_soft *_softA = new A_soft();
    B_soft *_softB = new B_soft();
    // 手机new
    A_phone *_phonea = new A_phone();
    _phonea->installsoft(_softA);
    _phonea->begin_soft();
    B_phone *_phoneb = new B_phone();
    _phoneb->installsoft(_softB);
    _phoneb->begin_soft();

    // 释放内存空间
    delete _phonea;
    delete _phoneb;
    delete _softA;
    delete _softB;

    return 0;
}