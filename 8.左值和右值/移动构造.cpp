#include <iostream>
#include <cstring>

using namespace std;

class A{
private:
    //成员属性
    char* _data;
public:
    //有参构造
    A(const char* p){
        cout<<"有参构造"<<endl;
        int size=strlen(p);
        _data=new char[size+1];
        strncpy(_data,p,size);
        _data[size]='\0';
    }
    //拷贝构造
    A(const A& a){
        cout<<"右值 拷贝构造"<<endl;
        int size=strlen(a._data);
        _data=new char[size+1];
        strncpy(_data,a._data,size);
        _data[size]='\0';
    }
    A(A&& a){
        cout<<"左值 拷贝构造"<<endl;
        _data=a._data;
        a._data=nullptr;
    }
    //赋值构造
    void operator=(const A& a){
        if(_data) delete[] _data;
        cout<<"左值 赋值拷贝"<<endl;
        int size=strlen(a._data);
        _data=new char[size+1];
        strncpy(_data,a._data,size);
        _data[size]='\0';
    }
    void operator=(A&& a){
        if(_data) delete[] _data;
        cout<<"右值 赋值拷贝"<<endl;
        _data=a._data;
        a._data=nullptr;
    }
    //析构函数
    virtual ~A(){
        if(_data) delete[] _data;
    }
    //功能函数
    void test(){
       if(_data){
        cout<<this<<"  "<<_data<<endl;
       } 
    }
};

int main(){
    A a("abcdef");
    a.test();

    A b(a);
    b.test();

    A c(move(a));
    c.test();
    return 0;
}