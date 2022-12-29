//定义 Point 类

#ifndef _Point_H_
#define _Point_H_

class Line;

class Point{
    friend class Line;
    //构造函数
    public:
    Point(float x=0,float y=0);
    //成员属性
    float _x,_y;
};

#endif