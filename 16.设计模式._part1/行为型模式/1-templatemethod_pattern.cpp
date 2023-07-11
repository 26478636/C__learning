#include <iostream>

using namespace std;

class Factory
{
public:
    virtual void template_mathod()
    {
        // 调用函数
        this->buildA();
        this->buildB();
        this->buildC();
        this->buildD();
    }
    virtual void buildA() = 0;
    virtual void buildB() = 0;
    virtual void buildC() = 0;
    virtual void buildD() = 0;
};

class BYD_Factory : public Factory
{
public:
    void buildA()
    {
        cout << "构建比亚迪零件A" << endl;
    }
    void buildB()
    {
        cout << "构建比亚迪零件B" << endl;
    }
    void buildC()
    {
        cout << "构建比亚迪零件C" << endl;
    }
    void buildD()
    {
        cout << "构建比亚迪零件D" << endl;
    }
};

class BMN_Factory : public Factory
{
public:
    void buildA()
    {
        cout << "构建宝马零件A" << endl;
    }
    void buildB()
    {
        cout << "构建宝马零件B" << endl;
    }
    void buildC()
    {
        cout << "构建宝马零件C" << endl;
    }
    void buildD()
    {
        cout << "构建宝马零件D" << endl;
    }
};

int main()
{
    BYD_Factory *_BYD = new BYD_Factory();
    _BYD->template_mathod();
    delete _BYD;
    return 0;
}