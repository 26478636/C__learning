#include <iostream>
#include <functional>

using namespace std;

class A{
private:
    int _n;
public:
    //仿函数
    void operator()(int n){
        cout<<"class operator() ="<<n*_n<<endl; 
    }
    //有参构造
    A(int n):_n(n){
        cout<<"class 有参构造 ="<<n<<endl;
    }
};

int main(){
    //auto & function
    auto func1=&A::operator();
    function<void(A*,int)> func2=&A::operator();
    A a(1);
    (a.*func1)(123);
    func2(&a,123);

    //有参构造
    auto func3=A(2);
    func3(10);
    //
    function<void(int)> func4=A(2);
    func4(10);
    return 0;
}