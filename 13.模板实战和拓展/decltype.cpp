#include <iostream>
using namespace std;

void test(){}

int main(){
    int a1=123,a2=456;
    const int a3=0;
    int* p=&a1;

    decltype(a1) b1;
    decltype(a3) b3=0;
    decltype(p) b4=0;

    decltype(a1+a2) b2;
    decltype(*p) b5=b2;
    decltype((p)) b6=p;

    decltype(1+2,2.0+3.4,1.0f) b7;

    auto func=&test;
    func();
    
    return 0;
}