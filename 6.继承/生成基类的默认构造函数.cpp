#include <iostream>

using namespace std;

class Father{
    //成员属性
    private:
    int _a;
    //构造函数
    public:
    Father(){
        cout<<"父类--默认构造函数"<<endl;
    }
    Father(int a):_a(a){
        cout<<"父类--有参构造函数"<<endl;
    }
    Father(const Father& f){
        cout<<"父类--拷贝构造函数"<<endl;
    }
    ~Father(){
        cout<<"父类--析构函数"<<endl;
    }
};

class Child:public Father{
    private:
    int _b;
    public:
    Child(){
        cout<<"子类--默认构造函数"<<endl;
    }
    Child(int b):_b(b){
        cout<<"子类--有参构造函数"<<endl;
    }
    Child(const Father& f){
        cout<<"子类--拷贝构造函数"<<endl;
    }
    ~Child(){
        cout<<"子类--析构函数"<<endl;
    }
};

int main(){
    Child child1;
    cout<<"----------"<<endl;
    Child child2(2);
    cout<<"----------"<<endl;
    Child child3(child1); 
    cout<<"----------"<<endl;
    return 0;
}