// 生成一个客户端希望的接口，但是实现功能是一样的
#include <iostream>

using namespace std;

// 继承方式
// 适配器基类
class base_adapter
{
public:
    // 请求接口
    virtual void request() = 0;
};
// 实际接口在这里实现的
class real_adapter
{
public:
    void special_request()
    {
        cout << "请求连接" << endl;
    }
};
// 适配器子类
class adapter : public base_adapter, public real_adapter
{
public:
    void request()
    {
        cout << "转接请求连接" << endl;
        this->special_request();
    }
};

// 组合方式
class aadapter : public base_adapter
{
private:
    real_adapter *real;

public:
    aadapter() = delete;
    // 有参构造
    aadapter(real_adapter *_real) : real(_real) {}
    // 成员函数
    void request()
    {
        real->special_request();
        cout << "连接成功" << endl;
    }
};

// 外部接口需求
void interface(base_adapter *_adapter)
{
    _adapter->request();
    cout << "连接成功" << endl;
}

int main()
{
    adapter *ada = new adapter();
    interface(ada);
    delete ada;

    cout << "----------" << endl;

    real_adapter *re = new real_adapter();
    aadapter *aa = new aadapter(re);
    aa->request();
    delete aa;
    delete re;
    return 0;
}