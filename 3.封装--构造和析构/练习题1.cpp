#include <iostream>
#include <string>

using namespace std;

//建立 People 类
class People{
    //成员属性
    private:
    string name;
    int age;
    float height;
    float weight;
    
    private:
    People() {};
    ~People() {};

    //成员方法
    public:
    static int count;
    static People* create(){
        count++;
        return new People();
    }
    //删除操作
    static void release(People* p1){
        delete p1;
    }
};

//count 定义
int People::count=0;

int main(){
    cout<<People::count<<endl;
    People* p1=People::create();
    cout<<People::count<<endl;
    return 0;
}