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
    //成员函数
    //p1+p2
    Point operator+(const Point& p){
        return Point(this->_x+=p._x,this->_y+=p._y);
    }
    //后置p1++
    Point operator++(int){
        Point p(this->_x+=p._x,this->_y+=p._y);
        this->_x++;
        this->_y++;
        return p;
    }
    //前置++p1
    Point operator++(){
        this->_x++;
        this->_y++;
        return *this;
    }
    //p1+=p2
    Point operator+=(const Point& p){
        this->_x+=p._x;
        this->_y+=p._y;
        return *this;
    }
    //p1*p2
    float operator*(const Point& p){
        return this->_x*p._x+this->_y*p._y;
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
    Point p1{1.2f,4.3f},p2{2.3f,3.3f};
    cout<<(p1+p2)<<endl;
    cout<<p1++<<endl;
    cout<<++p1<<endl;
    cout<<(p1+=p2)<<endl;
    cout<<p1*p2<<endl;
    cout<<p1<<endl;
    return 0;
}