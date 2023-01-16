//利用----lambda表达式
#include <iostream>
#include <functional>
using namespace std;

// //功能实现
// int ADD(int x,int y){
//     return x+y;
// }
function<int(int,int)> ADD=[](int x,int y){
    return x+y;
};
function<int(int,int)> SUB=[](int x,int y){
    return x-y;
};
function<int(int,int)> MAX=[](int x,int y){
    return x>y?x:y;
};
function<int(int,int)> MIN=[](int x,int y){
    return x>y?y:x;
};


//利用lambda表达式
auto Data=[](int x,int y){
    //这里传入一个函数
    //这里为什么不用引用(&)捕获
    return [=](function<int(int,int)> func){
        return func(x,y);
    };
};

int main(){
    auto data=Data(1,2);

    cout<<data(ADD)<<endl;
    cout<<data(SUB)<<endl;
    cout<<data(MAX)<<endl;
    cout<<data(MIN)<<endl;
    return 0; 
}