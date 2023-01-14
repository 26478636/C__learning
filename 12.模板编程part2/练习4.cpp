#include <iostream>

using namespace std;

template<int n>
class Choose{
public:
    static constexpr auto value="zhongguo";
};
template<>
class Choose<10>{
public:
    static constexpr auto value="beijing";
};
template<>
class Choose<21>{
public:
    static constexpr auto value="shanghai";
};
template<>
class Choose<100>{
public:
    static constexpr auto value="hangzhou";
};

int main(){
    cout<<Choose<10>::value<<endl;
    cout<<Choose<21>::value<<endl;
    cout<<Choose<571>::value<<endl;
    cout<<Choose<100>::value<<endl;
    return 0;
}