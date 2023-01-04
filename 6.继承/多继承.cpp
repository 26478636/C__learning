#include <iostream>

using namespace std;

//基类1
class Base1{
    public:
    Base1(){
        cout<<"基类1--默认构造"<<endl;
    }
    ~Base1(){
        cout<<"基类1--析构函数"<<endl;
    }
    void test1(){
        cout<<"生成base1"<<endl;
    }
    int a;
};

//基类2
class Base2{
    public:
    Base2(){
        cout<<"基类2--默认构造"<<endl;
    }
    ~Base2(){
        cout<<"基类2--析构函数"<<endl;
    }
    void test2(){
        cout<<"生成base2"<<endl;
    }
    int b;
};

//子类
class Child:public Base1,public Base2{
    public:
    Child(){
        cout<<"子类--默认构造"<<endl;
    }
    ~Child(){
        cout<<"子类--析构函数"<<endl;
    }
    void test1(){
        Base1::test1();
        cout<<"生成Child"<<endl;
    }
    void test2(){
        Base2::test2();
        cout<<"生成Child"<<endl;
    }
    int c;
};

int main(){
    Child child;
    cout<<"----------"<<endl;
    child.test1();
    child.test2();
    cout<<"----------"<<endl;
    cout<<&child<<endl;
    cout<<&child.a<<endl;
    cout<<&child.b<<endl;
    cout<<&child.c<<endl;
    return 0;
}