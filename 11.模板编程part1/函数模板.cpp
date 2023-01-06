#include <iostream>

using namespace std;

class Point{
public:
    Point(int x,int y){

    }
    int operator+(const Point& p){
        return 123;
    }
};

void print(int){
    cout<<"int输出"<<endl;
}
void print(float){
    cout<<"float输出"<<endl;
}
void print(double){
    cout<<"double输出"<<endl;
}
void print(Point){
    cout<<"Point输出"<<endl;
}

template<class T>
void print(T){
    cout<<"template输出"<<endl;
}

template<class T,class U>
auto add(T t,U u)->decltype(t+u){
    return t+u;
}

int main(){
    //Point P;
    print(1);
    print(1.2f);
    print(2.3);
    //print(P);
    cout<<add(1,2.1)<<endl;
    cout<<add(2.1,1)<<endl;
    cout<<add(Point(1,2),Point(2,3))<<endl;
    
    decltype(1+2) n;
    cout<<typeid(n).name()<<endl;
    return 0;
}