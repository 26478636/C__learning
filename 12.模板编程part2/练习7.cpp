//判断素数
#include <iostream>

using namespace std;

//111111
template<int i,int n>
class Input{
public:
    static constexpr int value=(n%i?i+1:0);
};
template<int i,int n>
class Output{
public:
    static constexpr int value=(i*i<=n?n:0);
};
//222222
template<int i,int n>
class judge_prime{
public:
    //递归
    static constexpr bool value=judge_prime<Input<i,n>::value,Output<i,n>::value>::value;
};
template<int n>
class judge_prime<0,n>{
public:
    static constexpr bool value=false;
};
template<int i>
class judge_prime<i,0>{
public:
    static constexpr bool value=true;
};
//333333
template<int n>
class is_prime{
public:
    static constexpr const char* value=(judge_prime<2,n>::value?"Yes":"No");
};
template<>
class is_prime<2>{
public:
    static constexpr const char* value="Yes";
};


int main(){
    cout<<is_prime<2>::value<<endl;
    cout<<is_prime<3>::value<<endl;
    cout<<is_prime<10>::value<<endl;
    cout<<is_prime<97>::value<<endl;
    cout<<is_prime<9997>::value<<endl;

    return 0;
}