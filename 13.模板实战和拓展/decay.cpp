#include <iostream>

using namespace std;

class A{};

void test(){}

int main(){
    using FUNC=void(*)();
    FUNC func=&test;
    using C8=decay<FUNC>::type;
    using C9=decay<void(*)()>::type;
    cout<<std::is_same<C8,FUNC>::value<<endl;
    cout<<std::is_same<C9,FUNC>::value<<endl;


    using C1=decay<A>::type;
    using C2=decay<A&>::type;
    using C3=decay<A&&>::type;
    using C4=decay<const A&>::type;
    using C5=decay<A[10]>::type;
    using C6=decay<A*>::type;
    using C7=decay<A*[10]>::type;

    cout<<std::is_same<C1,A>::value<<endl;
    cout<<std::is_same<C2,A>::value<<endl;
    cout<<std::is_same<C3,A>::value<<endl;
    cout<<std::is_same<C4,A>::value<<endl;
    cout<<std::is_same<C5,A*>::value<<endl;
    cout<<std::is_same<C6,A*>::value<<endl;
    cout<<std::is_same<C7,A**>::value<<endl;
    return 0;
}