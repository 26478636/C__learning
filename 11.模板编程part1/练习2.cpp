#include <iostream>

using namespace std;

namespace master{
    //template<class A>
    class print{
        public:
        //构造函数
        template<class B>
        print(B b){
            cout<<b<<" ";
        }
        //重载
        template<class C>
        print& operator()(C c){
            cout<<c<<" ";
            return *this;
        }
    };
}
int main(){
    master::print(666)("123")(456)("kaokeba")(789)("\n");
    return 0;
}