// 牵一发而动全身
#include <iostream>
#include <string>

using namespace std;

// 主
class Object;

// 从
class Observer
{
protected:
    string _name;

public:
    // 有参构造函数
    Observer(string name) : _name(name) {}
    // 牵一发而动全身 升级函数
    virtual void update(Object *object) = 0;
    // 内联函数
    inline string getName() { return _name; }
};
class A_observe : public Observer
{
public:
    using Observer::Observer;
    void update(Object *object)
    {
        cout << "升级类型Object: " << _name << endl;
    }
};
class B_object : public Observer
{
public:
    // 使用父类构造函数
    using Observer::Observer;
    void update(Object *object)
    {
        cout << "升级类型Object: " << _name << endl;
    }
};

int main()
{

    return 0;
}