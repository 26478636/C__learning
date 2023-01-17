//利用----仿函数
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

class Data{
private:
    //成员函数
    int _x,_y;
public:
    //有参构造
    Data(int x,int y):_x(x),_y(y){}
    //重载()
    int operator()(function<int(int,int)> func){
        func(_x,_y);
    }
};

int main(){
    auto data=Data(1,2);

    cout<<data(ADD)<<endl;
    cout<<data(SUB)<<endl;
    cout<<data(MAX)<<endl;
    cout<<data(MIN)<<endl;
    return 0; 
}