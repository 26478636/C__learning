#include <iostream>
#include <string>

using namespace std;

//定义 People 类
class People{
    friend int main();
    //成员属性
    private:
    string name;
    int age;
    string s1;
    string s2;
    //默认构造函数
    public:
    People()
    :name("Xiaowang")
    ,age(24)
    ,s1("123")
    ,s2(s1)
    {
        cout<<"默认构造，生成！！！"<<endl;
    }
    //有参构造函数
    People(string s) : name(s),age(24),s1("abc"),s2(s1){
        cout<<"有参构造，生成！！！"<<endl;
    }
    //拷贝构造函数
    People(const People& p) 
    :name(p.name)
    ,age(p.age)
    ,s1(p.s1)
    ,s2(p.s2){
        cout<<"拷贝构造，生成！！！"<<endl;
    }
    // People(){
    //     name="Xiaowang";
    //     age=24;
    //     s1="123";
    //     s2=s1;
    // }
};

int main(){
    People p;//默认调用构造函数
    cout<<p.name<<"_ _"<<p.age<<endl;
    cout<<"---------------------------"<<endl;
    People s1("Dawang");
    cout<<s1.name<<"_ _"<<s1.age<<endl;
    cout<<"---------------------------"<<endl;
    People p1(p);
    cout<<p1.name<<"_ _"<<p1.age<<endl;
    return 0;
}