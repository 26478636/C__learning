#include <iostream>
#include <functional>

using namespace std;

class A{
public:
    int _x;
    static int _y;
    A():_x(123){}
    //功能函数
    int add(int a,int b){
        return a+b;
    }
    static int ADD(int a,int b){
        return a+b;
    }
    //仿函数
    int operator()(int a,int b){
        return a+b;
    }
};
int A::_y=123;
int add(int a,int b){
    return a+b;
}

int main(){
    //全局区
    function<int(int,int)> func1=&add;
    cout<<func1(1,2)<<endl;
    cout<<"-----1-----"<<endl;
    //默认构造
    function<int(int,int)> func2=A();
    cout<<func2(1,2)<<endl;
    cout<<"-----2-----"<<endl;
    //this
    function<int(A*,int,int)> func3=&A::add;
    A a;
    cout<<func3(&a,1,2)<<endl;
    cout<<"-----3-----"<<endl;
    //静态
    function<int(int,int)> func4=&A::ADD;
    cout<<func4(1,2)<<endl;
    cout<<"-----4-----"<<endl;
    //lambda
    function<int(int,int)> func5=[](int a,int b){return a+b;};
    cout<<func5(1,2)<<endl;
    cout<<"-----5-----"<<endl;
    //成员属性
    function<int(A*)> func6=&A::_x;
    cout<<func6(&a)<<endl;
    cout<<"-----6-----"<<endl;
    // //全局区
    // function<int()> func7=&A::_y;
    // cout<<func7()<<endl;
    // cout<<"-----7-----"<<endl;
    return 0;
}