#include <iostream>
#include <functional>
#include <vector>

using namespace std;

void print(const vector<int>& arr,function<void(int)> func){
    for(auto i:arr){
        func(i);
    }
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    print(arr,[](int n){
        cout<<"n*2= "<<n*2<<endl;
    });
    return 0;
}