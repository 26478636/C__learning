#include <iostream>
#include <vector>

using namespace std;

void print(int i){

}

class A{
private:
    int _c;
public:
    A(int a,int b,int _c){};
};

int main(){
    print(123);
    print(123.0);

    auto arr1={1,2,3};
    A arr2={1,2,3};
    cout<<typeid(arr1).name()<<endl;

    vector<int> arr3(10);
    vector<int> arr4{10};

    for(auto i:arr3){
        cout<<i<<endl;
    }
    for(auto i:arr4){
        cout<<i<<endl;
    }

    return 0;
}
