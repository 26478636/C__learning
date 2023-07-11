// 工厂 指定 制造商 生产
// debug那么久，原来是字母拼错了，无语
#include <iostream>

using namespace std;

// 汽车产品
class base_car
{
protected:
    // 各个汽车所具备的一些性能
    int wheel;
    int engine;
    int color;

public:
    // 各个汽车能够实现的一些功能
    virtual void print_name() = 0;
    virtual void debug() = 0;
};
class BYD : public base_car
{
public:
    void print_name()
    {
        cout << "比亚迪汽车" << endl;
    }
    void debug()
    {
        cout << "wheel= " << wheel << " "
             << "engine= " << engine << " "
             << "color= " << color << endl;
    }
};
class BMN : public base_car
{
public:
    void print_name()
    {
        cout << "宝马汽车" << endl;
    }
    void debug()
    {
        cout << "wheel= " << wheel << " "
             << "engine= " << engine << " "
             << "color= " << color << endl;
    }
};

// 制造商
class Builder
{
public:
    virtual void buildA(base_car *car) = 0;
    virtual void buildB(base_car *car) = 0;
    virtual void buildC(base_car *car) = 0;
    virtual base_car *get_car() = 0;
};
// 比亚的制造商
class BYD_builder : public Builder
{
public:
    void buildA(base_car *car)
    {
        cout << "生产比亚迪零件a" << endl;
    }
    void buildB(base_car *car)
    {
        cout << "生产比亚迪零件b" << endl;
    }
    void buildC(base_car *car)
    {
        cout << "生产比亚迪零件c" << endl;
    }
    base_car *get_car()
    {
        base_car *car = new BYD();
        buildA(car);
        buildB(car);
        buildC(car);
        return car;
    }
};
class BMN_builder : public Builder
{
public:
    void bulidA(base_car *car)
    {
        cout << "生产宝马零件a" << endl;
    }
    void bulidB(base_car *car)
    {
        cout << "生产宝马零件b" << endl;
    }
    void bulidC(base_car *car)
    {
        cout << "生产宝马零件c" << endl;
    }
    base_car *get_car()
    {
        base_car *car = new BMN();
        buildA(car);
        buildB(car);
        buildC(car);
        return car;
    }
};
// 工厂制造
class Factory
{
public:
    Builder *_builder;
    void set_builder(Builder *builder)
    {
        _builder = builder;
    }
    base_car *get_new_car()
    {
        if (_builder)
        {
            return _builder->get_car();
        }
        return nullptr;
    }
};
int main()
{
    Factory factory;
    BYD_builder *builder = new BYD_builder();
    factory.set_builder(builder);
    auto car = factory.get_new_car();
    car->debug();
    delete car;
    delete builder;
    return 0;
}