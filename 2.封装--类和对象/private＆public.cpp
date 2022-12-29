#include <iostream>

using namespace std;

class People{
    public:
    char name[10];
    int age;
    double weight;
    double height;

    void say(string word);
    void run();
};

class A{

};

int main(){
    People xiaowang;
    A a;

    cout<<"sizeof: "<<sizeof(People)<<"sizeof: "<<sizeof(xiaowang)<<endl;
    cout<<"sizeof: "<<sizeof(A)<<"sizeof: "<<sizeof(a)<<endl;
  
    cout<<"name: "<<&xiaowang.name<<endl;
    cout<<"age: "<<&xiaowang.age<<endl;
    cout<<"weight: "<<&xiaowang.weight<<endl;
    cout<<"height: "<<&xiaowang.height<<endl;

    return 0;
}