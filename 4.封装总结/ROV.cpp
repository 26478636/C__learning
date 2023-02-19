#include <iostream>
#include <cstring>

using namespace std;

class People{
public:
    People(){
        cout<<"默认构造"<<endl;
    }
    People(string name){
        cout<<"有参构造"<<endl;
    }
    People(const People& p){
        cout<<"拷贝构造"<<endl;
    }
};

People test(){
    People temp_a("master");
    return temp_a;
}

int main(){
    // test();
    People a=test();
    return 0;
}