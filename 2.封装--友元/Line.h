#ifndef _Line_H_
#define _Line_H_

#include "Point.h"

class Line{
    public:
    //构造函数
    Line(const Point& p1,const Point& p2);
    //成员方法
    float getDistance();
    private:
    //成员属性
    Point p1,p2;
};

#endif