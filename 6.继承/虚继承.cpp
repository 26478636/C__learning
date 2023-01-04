#include <iostream>

using namespace std;

struct A{
    int a;
    A(){
        cout<<"A_默认构造"<<endl;
    }
    ~A(){
        cout<<"A_析构函数"<<endl;
    }
};

struct B:virtual public A{
    int b;
    B(){
        cout<<"B_默认构造"<<endl;
    }
    ~B(){
        cout<<"B_析构函数"<<endl;
    }
};

struct C:public B{
    int c;
    C(){
        cout<<"C_默认构造"<<endl;
    }
    ~C(){
        cout<<"C_析构函数"<<endl;
    }
};

int main(){
    C c;
    cout<<"----------"<<endl;
    cout<<&c<<endl;
    cout<<&c.a<<endl;
    cout<<&c.b<<endl;
    cout<<&c.c<<endl;
    cout<<"----------"<<endl;
    A* pa=&c;
    B* pb=&c;
    cout<<pa<<endl;
    cout<<pb<<endl;
    return 0;
}