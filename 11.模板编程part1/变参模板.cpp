#include <iostream>

using namespace std;

namespace master{
    template<class A>
    void print(const A& a){
        cout<<a<<endl;
    }
    template<class A,class ...ARGS>
    void print(const A& a,ARGS ...args){
        cout<<a<<" ";
        print(args...);
    }

    template<class A>
    A sum1(const A& a){
        return a;
    }
    template<class A,class ...ARGS>
    A sum1(const A& a,ARGS ...args){
        return a+sum1(args...);
    }
    template<class A>
    A sum2(const A& a){
        if(a==1) return 1;
        return a+sum2(a-1);
    }
}

int main(){
    master::print(666,"123",456,"kaikeba",789,"\n");

    cout<<master::sum1(1,2,3,4,5,6,7,8,9,10)<<endl;
    cout<<master::sum2(10)<<endl;
    
    return 0;
}