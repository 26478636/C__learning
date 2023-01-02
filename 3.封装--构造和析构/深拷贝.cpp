#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//定义 People 类
class People{
    friend int main();

    //成员属性
    private:
    char* name;
    int age;

    //构造函数
    //默认构造函数
    public:
    People():name(nullptr),age(24){
        name=new char[20];
        memset(name,0,20);
        strcpy(name,"Xiaowang");
        cout<<"默认构造函数"<<endl;
    };
    //有参构造函数
    People(string s) : name(nullptr),age(24){
        name=new char[20];
        memset(name,0,20);
        strcpy(name,s.c_str());
        cout<<"有参构造函数"<<endl;
    }
    //拷贝构造函数
    People(const People& p) : name(),age(p.age){
        name=new char[20];
        memset(name,0,20);
        strcpy(name,p.name);
        cout<<"拷贝构造函数"<<endl;
    }
    //析构函数
    ~People(){
        delete[] name;
        cout<<"析构函数"<<endl;
    }
};

int main(){
    People a1;

    People a2("Xiaowang");

    People a3(a1);

    return 0;
}