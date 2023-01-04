#include <iostream>

using namespace std;

//Fraction 类
class Fraction{
    //成员属性
    private:
    int _x,_y;
    //构造函数
    public:
    Fraction(int x,int y):_x(x),_y(y){

    }
    //功能函数
    //最大公约数
    int measure(int x,int y){
        int z=y;
        while(x%y!=0){
            z=x%y;
            x=y;
            y=z;
        }
        return z;
    }
    //f1+f2
    Fraction operator+(const Fraction& f){
        int x=this->_x*f._y+this->_y*f._x;
        int y=this->_y*f._y;
        int z=measure(x,y);
        return Fraction(x/z,y/z);
    } 
    //f1*f2
    Fraction operator*(const Fraction& f){
        int x=this->_x*f._x;
        int y=this->_y*f._y;
        int z=measure(x,y);
        return Fraction(x/z,y/z);
    }
    Fraction& operator-(){
        this->_x=-this->_x;
        return *this;
    }
    Fraction& operator+=(const Fraction& f){
        int x=this->_x*f._y+this->_y*f._x;
        int y=this->_y*f._y;
        int z=measure(x,y);
        this->_x=x/z;
        this->_y=y/z;
        return *this;
    }
    Fraction& operator*=(const Fraction& f){
        int x=this->_x*f._x;
        int y=this->_y*f._y;
        int z=measure(x,y);
        this->_x=x/z;
        this->_y=y/z;
        return *this;
    }
    bool operator==(const Fraction& f){
        return this->_x*f._y==this->_y*f._x;
    }
    bool operator<(const Fraction& f){
        return this->_x*f._y<this->_y*f._x;
    }
    bool operator>(const Fraction& f){
        return this->_x*f._y>this->_y*f._x;
    }
    //功能输出
    public:
    friend ostream& operator<<(ostream& os,const Fraction& f){
        os<<f._x<<"/"<<f._y<<endl; 
        return os;
    }
};
int main(){
    Fraction f1{1,4},f2{1,6};
    cout<<(f1+f2)<<endl;
    cout<<(f1*f2)<<endl;
    cout<<(-f1)<<endl;
    cout<<(f1+=f2)<<endl;
    cout<<(f1*=f2)<<endl;
    if(f1==f2){
        cout<<"相等"<<endl;
    }
    if(f1<f2){
        cout<<"小于"<<endl;
    }
    if(f1>f2){
        cout<<"大于"<<endl;
    }
    return 0;
}