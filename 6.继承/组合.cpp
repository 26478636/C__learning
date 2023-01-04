#include <iostream>

using namespace std;

class A{
    public:
    void print(){
        cout<<"打印 A"<<endl;
    }
};

class B{
    private:
    A a;
    public:
    void print(){
        a.print();
    }
};

int main(){
    B b;
    b.print();
    return 0;
}