#include <iostream>

using namespace std;

class A{
public:
    A()=delete;

    void print(){

    }
    
    int value(){
        return 1;
    }
};

int main(){
    decltype(std::declval<A>().value()) index=123;
    cout<<index<<endl;
    return 0;
}