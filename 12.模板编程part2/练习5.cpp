#include <iostream>

using namespace std;

template<int n>
class A{
public:
    static constexpr bool value=(n>=60);
};
template<int n>
class Score{
public:
    static constexpr const char* value=(A<n>::value?"Yes":"No");
};

int main(){
    cout<<Score<65>::value<<endl;
    cout<<Score<40>::value<<endl;
    return 0;
}