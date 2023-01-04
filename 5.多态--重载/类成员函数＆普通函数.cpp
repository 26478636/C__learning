#include <iostream>

using namespace std;

//类成员函数
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
    //成员方法
    void print(int n){
        cout<<"x="<<(int)_x<<"..."<<"y="<<(int)_y<<endl;
    }
    void print(float n){
        cout<<"x="<<_x<<"..."<<"y="<<_y<<endl;
    }
    //友元方法
    friend void print(const Point& p,int n);
    friend void print(const Point& p,float n);
};

//普通函数（全局函数）
void print(const Point& p,int n){
    cout<<"x="<<(int)p._x<<"..."<<"y="<<(int)p._y<<endl;
}
void print(const Point& p,float n){
    cout<<"x="<<p._x<<"..."<<"y="<<p._y<<endl;
}

int main(){
    Point p1{1.2f,2.6f},p2{2.2f,5.6f};
    p1.print(2);
    p2.print(2.2f);
    cout<<"---------------"<<endl;
    print(p1,2);
    print(p2,3.4f);
    return 0;
}