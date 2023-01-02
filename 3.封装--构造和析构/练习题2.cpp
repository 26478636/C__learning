//const 类型 注意事项
#include <iostream>
#include <string>

using namespace std;

//建立People 类
class People{
    //const 类型
    private:
    const string name;
    mutable int age;
    float height;
    float weight;

    public:
    People() 
    :name("Xiaowang")
    ,age(24)
    ,height(166)
    ,weight(106) {};
    ~People() {};

    public:
    string geName() const{
        age++;
        //报错---哈哈哈
        //const对应const
        //addAge();
        return name;
    }
    void addAge(){
        age++;
    }
};

int main(){
    return 0;
}
