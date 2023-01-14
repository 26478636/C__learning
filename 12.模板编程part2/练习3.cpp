#include <iostream>

using namespace std;

template<bool A,class B,class C>
class IFELSE{
public:
    using type=B;
};
template<class B,class C>
class IFELSE<true,B,C>{
public:
    using type=B;
};
template<class B,class C>
class IFELSE<false,B,C>{
public:
    using type=C;
};

int main(){
    IFELSE<true,int,double>::type a;
    IFELSE<false,int,double>::type b;
    
    cout<<typeid(a).name()<<endl;
    cout<<typeid(b).name()<<endl;
    return 0;
}