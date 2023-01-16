#include <iostream>
#include <functional>

using namespace std;

class A{
public:
    //全局函数
    static void print1(int n){
        cout<<"class static print1 ="<<n<<endl;
    }
    //类成员函数
    void print2(int n){
        cout<<"class print2 ="<<n<<endl;
    }
};

int main(){
    //auto 
    auto func1=&A::print1;
    auto func2=&A::print2;
    func1(123);
    A a;
    (a.*func2)(123);
    cout<<"----------"<<endl;
    //function
    function<void(int)> func3=&A::print1;
    function<void(A*,int)> func4=&A::print2;
    func3(123);
    func4(&a,123);
    cout<<"----------"<<endl;

    return 0;
}