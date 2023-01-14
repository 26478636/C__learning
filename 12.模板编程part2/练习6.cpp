#include <iostream>

using namespace std;

template<int n>
class A{
public:
    static constexpr bool value=(n%2);
};
template<int n>
class is_even{
public:
    static constexpr const char* value=(A<n>::value?"Yes":"No");
};

int main(){
    //是否为素数
    cout<<is_even<2>::value<<endl;
    cout<<is_even<4>::value<<endl;
    return 0;
}