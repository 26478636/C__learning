#include <iostream>
#include <functional>

using namespace std;

int main(){
    int x=2;
    //function
    function<void(int)> func1=[x](int n){
        cout<<"n*x= "<<n*x<<endl;
    };
    auto func2=[x](int n){
        cout<<"n*x= "<<n*x<<endl;
    };
    func1(123);
    func2(123);
    return 0;
}