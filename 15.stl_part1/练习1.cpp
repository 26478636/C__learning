#include <iostream>
#include <functional>
using namespace std;

void test(int a,int b,int c,int d){
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    cout<<"c="<<c<<endl;
    cout<<"d="<<d<<endl;
    return ;
}

int main(){
    function<void(int,int,int,int)> func1=bind(&test,placeholders::_4,placeholders::_3,placeholders::_2,placeholders::_1);
    function<void(int,int,int)> func2=bind(&test,placeholders::_1,placeholders::_2,placeholders::_3,4);
    function<void(int,int,int)> func3=bind(&test,placeholders::_3,placeholders::_1,placeholders::_2,4);
    function<void(int,int,int)> func4=bind(&test,1,placeholders::_3,placeholders::_1,placeholders::_2);
    function<void()> func5=bind(&test,1,2,3,4);

    func1(4,3,2,1);
    func2(1,2,3);
    func3(2,3,1);
    func4(3,4,2);
    func5();
    return 0;
}