#include <iostream>
#include "Point.h"
#include "Line.h"

using namespace std;

int main(){
    Point p1{1.2f,2.3f},p2{3.2f,2.4f};
    Line line(p1,p2);
    cout<<"distance: "<<line.getDistance()<<endl;
    return 0;
}