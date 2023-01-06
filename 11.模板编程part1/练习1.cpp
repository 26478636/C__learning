#include <iostream>

using namespace std;

namespace master{
    template<class T>
    void swap(T& a,T& b){
        T z=a;
        a=b;
        b=z;
        cout<<"a="<<a<<", b="<<b<<endl;
    }
}

int main(){
    int a=123,b=456;
    master::swap(a,b);
    return 0;
}