#include <iostream>

using namespace std;

class Animal{
public:
    virtual void run(){
        cout<<"animal run"<<endl;
    }
    virtual void eat(){
        cout<<"animal eat"<<endl;
    }
    virtual void speak(){
        cout<<"animal speak"<<endl;
    }
    void actionEat(){
        this->run();
        this->run();
        this->speak();
    }
};
class Cat:public Animal{
public:
    void run(){
        cout<<"Cat run"<<endl;
    }
    void eat(){
        cout<<"Cat eat"<<endl;
    }
    void speak(){
        cout<<"Cat speak"<<endl;
    }
};
class Dog:public Animal{
public:
    void run(){
        cout<<"Dog run"<<endl;
    }
    void eat(){
        cout<<"Dog eat"<<endl;
    }
    void speak(){
        cout<<"Dog speak"<<endl;
    }
};

int main(){
    Animal* animals[10];
    for(int i=0;i<10;i++){
        if(i%2==1){
            animals[i]=new Cat();
        }else{
            animals[i]=new Dog();
        }
    }
    for(auto animal:animals){
        animal->actionEat();
    }
    return 0;
}