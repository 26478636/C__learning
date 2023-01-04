#include <iostream>

using namespace std;

//Point 类
class Point{
    //成员属性
    private:
    float _x,_y;
    //构造函数
    public:
    Point():_x(0),_y(0){

    }
    Point(float x,float y):_x(x),_y(y){

    }
    //友元函数
    friend ostream& operator<<(ostream& os,const Point& p);  
};

//实现功能
ostream& operator<<(ostream& os,const Point& p){
    os<<"x="<<p._x<<"......"<<"y="<<p._y<<endl;
    return os;
}

int main(){
    Point p1{1.2f,4.3f};

    cout<<p1<<endl;
    return 0;
}