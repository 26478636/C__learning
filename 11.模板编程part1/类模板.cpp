#include <iostream>

using namespace std;

//模板类
template<class T>
class A{
public:
    T t;
    template<class U>
    void print(U u){
        cout<<"模板类输出"<<endl;
    }
};
template<>
class A<int>{
public:
    void print(int n){
        cout<<"特化输出"<<endl;
    }
};

template<int>
class B{
    public:
    void print(){
        cout<<"模板2"<<endl;
    }
};
template<>
class B<1>{
    public:
    void print(){
        cout<<"模板2--特化"<<endl;
    }
};

int main(){
    A<double> a;
    a.print(3);
    cout<<sizeof(a)<<endl;
    cout<<sizeof(A<int>)<<endl;
    cout<<"-------------"<<endl;
    A<int> b;
    b.print(3);
    cout<<"-------------"<<endl;
    B<123> c;
    c.print();
    B<1> b1;
    c.print();
    return 0;
}