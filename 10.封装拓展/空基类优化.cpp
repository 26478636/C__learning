#include <iostream>

using namespace std;

struct A{

};

struct AA{

};

struct B:virtual public A{
    //A a;
};

struct C:virtual public A,virtual public B{

};

struct D:public A,public AA{

};

int main(){
    A arr[10];
    A* p1=new A();
    A* p2=new A();

    cout<<"A: "<<sizeof(A)<<endl;
    cout<<"B: "<<sizeof(B)<<endl;
    cout<<"C: "<<sizeof(C)<<endl;
    cout<<"D: "<<sizeof(D)<<endl;

    return 0;
}