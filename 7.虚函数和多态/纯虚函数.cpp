#include <iostream>

using namespace std;

class A{
public:
    virtual void test()=0;
};

class B:public A{
// public:
//     void test(){
//         cout<<"BBBBBBBBBB"<<endl;
//     }
};

class C:public B{
public:
    void test(){
        cout<<"CCCCCCCCCC"<<endl;
    }
};

int main(){
    A* a=new C();
    a->test();
    return 0;
}