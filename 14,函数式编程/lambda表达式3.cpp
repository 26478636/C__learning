#include <iostream>
#include <functional>

using namespace std;

class A{
public:
    void print(){
        cout<<"-----print-----"<<endl;
    }
    function<void(void)> test(){
        return [this](){
            print();
        };
    }
};

int main(){
    A a;
    auto func1=a.test();
    func1();
    return 0;
}