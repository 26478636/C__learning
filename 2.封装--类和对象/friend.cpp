#include <iostream>
#include <math.h>

using namespace std;

//Point 点类
class Point{
    friend float getDistance(const Point&,const Point&);
    friend class Line;
    //friend int main();
    //构造函数
    public:
    Point(float x=0,float y=0){
        _x=x;
        _y=y;
    }
    private:
    float _x,_y;
};

//Line 线类
class Line{
    public:
    float getDistance(){
        return sqrt((p1._x-p2._x)*(p1._x-p2._x)+(p1._y-p2._y)*(p1._y-p2._y));
    }
    Line(const Point& start,const Point& end){
        p1=start;
        p2=end;
    }
    private:
    Point p1,p2;
};

//计算距离的函数
float getDistance(const Point& p1,const Point& p2){
    return sqrt((p1._x-p2._x)*(p1._x-p2._x)+(p1._y-p2._y)*(p1._y-p2._y));
}

int main(){
    Point p1{1.2f,3.4f},p2{1.3f,2.3f};
    cout<<"distance:"<<getDistance(p1,p2)<<endl;
    return 0;
}