#include <iostream>
#include <functional>

using namespace std;

void print1(int n){
    cout<<"n="<<n<<endl;
}

void print2(int n){
    cout<<"n*2="<<n*2<<endl;
}

void print3(function<void(int)> func,int n){
    func(n);
}

int main(){
    int a1;
    int* p1=&a1;

    function<void(int)> func1=&print1;
    func1(123);

    function<void(int)> func2=&print2;
    func2(123);

    auto func3=&print2;
    func3(123);

    print3(&print2,123);

    decltype(&print2) func4=&print2;
    func4(123);

    decltype(print2)* func5=&print2;
    func5(123);
    return 0;
}