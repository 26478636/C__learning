#include <iostream>

using namespace std;

// void print(int n){
//     cout<<"值传递"<<endl;
// }
void print(int& n){
    cout<<"左值引用"<<endl;
}
void print(int&& n){
    cout<<"右值引用"<<endl;
}
void print(const int& n){
    cout<<"const 左值引用"<<endl;
}
void print(const int&& n){
    cout<<"const 右值引用"<<endl;
}

int main(){
    int x=1,y;
    print(x+y);
    print(x++);
    print(++x);
    cout<<"-------------------"<<endl;

    int a=1;
    int& b=a;
    const int c=2;
    const int& d=a;
    int&& e=1;
    const int&& f=10;
    print(a);
    print(b);
    print(c);
    print(d);
    print(e);
    print(f);

    print(123);
    print(move(e));
    print(move(f));
    
    return 0;
}