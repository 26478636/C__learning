#include <iostream>

using namespace std;

class A{
public:
    virtual void print(){
        cout<<"打印A"<<endl;
    }
};

class B:public A{ 
public:
    void print(){
        cout<<"打印B"<<endl;
    }
};

int main(){
    A a;
    B b;
    a.print();
    b.print();
    cout<<"----------"<<endl;
    A& p1=b;
    p1.print();
    cout<<"----------"<<endl;
    A* p2=new B();
    p2->print();
    cout<<"----------"<<endl;
    return 0;
}