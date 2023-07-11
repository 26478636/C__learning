// 希望你放弃他

#include <iostream>
#include <vector>

using namespace std;

// 汽车的基类
class base_car
{
public:
    // 虚继承
    // 我认为，等待基类初始化的过程
    virtual void name_car() = 0;
};
// 各种种类的汽车
class BYD : public base_car
{
public:
    // 成员函数
    void name_car()
    {
        cout << "生产比亚迪" << endl;
    }
};
class BMN : public base_car
{
public:
    // 成员函数
    void name_car()
    {
        cout << "生产宝马" << endl;
    }
};
// 工厂初始化
class Factory
{
public:
    // 创建成员函数
    base_car *get_car(string s)
    {
        if (s == "BYD")
        {
            return new BYD();
        }
        else if (s == "BMN")
        {
            return new BMN();
        }
        else
            return nullptr;
    }
};

int main()
{
    Factory _factory;
    vector<base_car *> vec;
    vec.push_back(_factory.get_car("BYD"));
    vec.push_back(_factory.get_car("BMN"));
    vec.push_back(_factory.get_car("STR"));
    vec.push_back(_factory.get_car("VTF"));
    vec.push_back(_factory.get_car("FDS"));

    // 容器创建成功
    for (auto it : vec)
    {
        if (it)
            it->name_car();
        else
            cout << "创建失败" << endl;
    }

    cout << "工厂工作结束" << endl;
    return 0;
}