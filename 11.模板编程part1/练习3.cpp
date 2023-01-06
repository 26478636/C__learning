#include <iostream>

using namespace std;

namespace master{
    template<int i,class A,class ...args>
    struct TYPE{
        using type=typename TYPE<i-1,args...>::type;
    };
    template<class A,class ...args>
    struct TYPE<0,A,args...>{
        using type=A;
    };
}
int main(){
    //0,1,2,3......
    master::TYPE<1,int,double,float,int>::type n1;
    master::TYPE<2,int,double,float,int,float>::type n2;
    cout<<typeid(n2).name()<<endl;

    return 0;
}