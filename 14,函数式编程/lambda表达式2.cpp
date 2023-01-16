#include <iostream>
#include <functional>

using namespace std;

int main(){
    int x=2;
    {
        cout<<"x= "<<x<<"address= "<<&x<<endl;
    }
    //lambda表达式--auto--function
    // auto func1=[&](int n){  
    //     cout<<"n*x= "<<n*x<<endl;
    //     x=9;
    //     cout<<"x= "<<x<<"address= "<<&x<<endl;
    // };
    function<void(int)> func2=[&](int n){
        cout<<"n*x= "<<n*x<<endl;
        x=9;
        cout<<"x= "<<x<<"address= "<<&x<<endl;
    };
    func2(123);
    cout<<"x= "<<x<<"address= "<<&x<<endl;
    return 0;
}