#include <iostream>
#include <functional>
using namespace std;

int add(int a,int b){
    cout<<"a= "<<a<<" b= "<<b<<endl;
    return a+b;
}

int main(){
    function<int(int,int)> func1=&add;
    cout<<func1(1,2)<<endl;
    function<int()> func2=bind(&add,1,2);
    cout<<func2()<<endl;
    function<int(int)> func3=bind(&add,1,placeholders::_1);
    cout<<func3(2)<<endl;
    function<int(int)> func4=bind(&add,placeholders::_1,2);
    cout<<func4(1)<<endl;
    return 0;
}