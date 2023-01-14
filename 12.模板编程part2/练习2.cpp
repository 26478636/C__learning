#include <iostream>

using namespace std;

template<int m,int n>
class Add{
public:
    static constexpr int value=m+n;
};

template<int n>
class Sum{
public:
    static constexpr int value=n+Sum<n-1>::value;
};

template<>
class Sum<1>{
public:
    static constexpr int value=1;
};

int main(){
    cout<<Add<123,456>::value<<endl;
    cout<<Sum<100>::value<<endl;
    return 0;
}