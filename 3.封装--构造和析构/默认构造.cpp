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
    //构造函数
    public:
    People()
    :name("Xiaowang")
    ,age(24)
    ,s1("123")
    ,s2(s1)
    {
        cout<<"默认构造，生成！！！"<<endl;
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
    return 0;
}