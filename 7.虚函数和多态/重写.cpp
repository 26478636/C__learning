#include <iostream>

using namespace std;

class A{
public:
    void print(){
        cout<<"打印--A"<<endl;
    }
};

class B:public A{
public:
    void print(){
        cout<<"打印--B"<<endl;
    }
};

int main(){
    A a;
    B b;
    a.print();
    b.print();
    cout<<"---------"<<endl;
    A& pa=b;
    pa.print();
    b.print();
    cout<<"---------"<<endl;
    return 0;
}