#include <iostream>

using namespace std;

class A{
    public:
    void run(){
        cout<<"this地址---"<<this<<endl;
    } 
    int a;  
};
class B:virtual public A{  
};
class C:virtual public A{
};
class D:public B,public C{
};

using namespace std;

int main(){
    // D d;
    // //d.run();
    // d.B::run();
    // d.C::run();
    // ((B)d).run();
    // ((C)d).run();
    // int* a=nullptr;
    // ((B*)a)->run();
    // return 0;
    B b;
    cout<<&b<<endl;
    cout<<&b.a<<endl;
    cout<<"----------"<<endl;
    cout<<sizeof(A)<<endl;
    cout<<sizeof(B)<<endl;
    cout<<sizeof(C)<<endl;
    cout<<sizeof(D)<<endl;
    return 0;
}