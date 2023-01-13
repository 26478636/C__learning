#include <iostream>

using namespace std;

//class A final{
class A{
public:
    //virtual void print() final{
    virtual void print(){

    }
};

class B:public A{
public:
    void print() override{

    }
    void test(){
        cout<<"test()"<<endl;
    }
    void test() const{
        cout<<"test() const"<<endl;
    }
};

int main(){
    A a;
    B b;
    b.test();
    const B b1;
    b1.test();
    return 0;
}